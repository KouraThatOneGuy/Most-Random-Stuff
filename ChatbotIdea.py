import random
import re

# Sample responses
responses = {
    "hello": ["Hi there!", "Hello!", "Greetings!", "How can I assist you today?"],
    "bye": ["Goodbye!", "See you later!", "Take care!"],
    "how are you": ["I'm just a computer program, but thanks for asking!", "Doing well, how about you?"],
    "default": ["I'm sorry, I don't understand that.", "Can you rephrase your question?"]
}

def get_response(user_input):
    user_input = user_input.lower()
    for keyword in responses:
        if re.search(r'\b' + re.escape(keyword) + r'\b', user_input):
            return random.choice(responses[keyword])
    return random.choice(responses["default"])

def chatbot():
    print("Chatbot: Hello! Type 'bye' to exit.")
    while True:
        user_input = input("You: ")
        if user_input.lower() == 'bye':
            print("Chatbot: Goodbye!")
            break
        response = get_response(user_input)
        print("Chatbot:", response)

if __name__ == "__main__":
    chatbot()
