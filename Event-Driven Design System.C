#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <librdkafka/rdkafka.h>

void produce_message(const char *topic_name, const char *message) {
    rd_kafka_t *rk;          // Producer instance
    rd_kafka_conf_t *conf;   // Temporary configuration object
    char errstr[512];        // Error string
    rd_kafka_topic_t *rkt;   // Topic object

    conf = rd_kafka_conf_new();
    rd_kafka_conf_set_dr_msg_cb(conf, dr_msg_cb);

    rk = rd_kafka_new(RD_KAFKA_PRODUCER, conf, errstr, sizeof(errstr));
    rkt = rd_kafka_topic_new(rk, topic_name, NULL);

    rd_kafka_produce(rkt, RD_KAFKA_PARTITION_UA, RD_KAFKA_MSG_F_COPY,
                     (void *)message, strlen(message), NULL, 0, NULL);

    rd_kafka_flush(rk, 10 * 1000); // Wait for max 10 seconds

    rd_kafka_topic_destroy(rkt);
    rd_kafka_destroy(rk);
}

void dr_msg_cb(rd_kafka_t *rk, const rd_kafka_message_t *rkmessage, void *opaque) {
    if (rkmessage->err) {
        fprintf(stderr, "Message delivery failed: %s\n", rd_kafka_err2str(rkmessage->err));
    } else {
        printf("Message delivered to %s [%d] at offset %lld\n",
               rd_kafka_topic_name(rkmessage->rkt),
               rkmessage->partition,
               rkmessage->offset);
    }
}

int main() {
    const char *topic = "test_topic";
    const char *message = "Hello, Kafka!";
    
    produce_message(topic, message);
    
    return 0;
}
