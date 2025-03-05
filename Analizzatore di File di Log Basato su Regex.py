import re
from collections import Counter

def analizza_log(file_path):
    with open(file_path, 'r') as file:
        log_data = file.readlines()

    error_pattern = re.compile(r'(?P<timestamp>\S+ \S+) \S+ \S+ \[(?P<ip>\S+)\] "(?P<request>[^"]+)" (?P<status>\d+)')
    error_counter = Counter()
    timestamps = []

    for line in log_data:
        match = error_pattern.search(line)
        if match:
            status = match.group('status')
            ip = match.group('ip')
            timestamp = match.group('timestamp')
            if status.startswith('5'):  # Errori del server
                error_counter[ip] += 1
                timestamps.append(timestamp)

    print("Frequenza degli errori per IP:")
    for ip, count in error_counter.items():
        print(f"{ip}: {count} errori")

    print("\nTimestamps degli errori:")
    for timestamp in timestamps:
        print(timestamp)

# Esempio di utilizzo
# analizza_log('server.log')
