#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_RESPONSES 5
#define MAX_INPUT 256

// Structure to hold keyword-response pairs
typedef struct {
    char *keyword;
    char *responses[MAX_RESPONSES];
} ChatResponse;

// Predefined chatbot responses
ChatResponse database[] = {
    {"hello", {"Hi there!", "Hello!", "Hey! How can I help?", "Greetings!", "Hi! Nice to meet you!"}},
    {"how are you", {"I'm just a bot, but I'm doing great!", "Feeling chatty today!", "I'm here to help!", "I'm doing well, what about you?", "Great! Thanks for asking!"}},
    {"your name", {"I'm ChatBot, your virtual assistant!", "I go by ChatBot, nice to meet you!", "You can call me ChatBot!", "My name is ChatBot, and I'm here to assist!", "I'm ChatBot, what's yours?"}},
    {"bye", {"Goodbye! Have a great day!", "See you later!", "Bye! Come back soon!", "Take care!", "Farewell, human!"}},
    {"help", {"I can answer simple questions! Try asking about my name, how I am, or say hello.", "I'm here to chat! Try asking me about the weather, my name, or just say hi!", "Need help? Just type a message, and I'll try to respond!", "I can have a fun chat with you! Try asking about my name or greeting me.", "Looking for something? Just ask!"}},
    {"weather", {"I can't check the weather, but I hope it's nice where you are!", "I don't have a weather forecast, but I hope it's sunny!", "Weather? I wish I had a window!", "I can't predict the weather, but I hope it's good for a walk!", "Maybe check a weather website for updates!"}},
    {"joke", {"Why don't programmers like nature? Too many bugs!", "What do you call 8 hobbits? A Hob-byte!", "Why do Java developers wear glasses? Because they don’t C#!", "What’s a computer’s favorite snack? Microchips!", "Why did the scarecrow become a coder? Because he was outstanding in his field!"}},
    {"time", {"I don't have a watch, but it's always a good time to chat!", "Time is just an illusion... but your device can tell you the exact time!", "It's time to have a great conversation!", "Check your clock! Time flies when you're chatting!", "I run on timeless code, so I'm always here!"}},
    {"date", {"I can’t check the calendar, but today is a great day!", "Any day spent chatting is a good day!", "Your device knows the date better than I do!", "Every day is a fresh start, right?", "Check your calendar for today’s date!"}},
    {"food", {"I don't eat, but I hear pizza is amazing!", "I wish I could try sushi!", "Burgers or pizza? Tough choice!", "Food is fuel! What's your favorite dish?", "I can't eat, but I can talk about food all day!"}},
    {"movie", {"I love talking about movies! What's your favorite?", "I hear Inception is mind-blowing!", "Sci-fi movies are the best!", "Have you watched any good movies lately?", "Movies are a great way to escape reality!"}},
    {"music", {"I don't have ears, but I love talking about music!", "What's your favorite song?", "Music makes life better!", "I bet you have great taste in music!", "Do you prefer pop or rock?"}},
    {"sports", {"Do you like football or basketball?", "Sports keep you active!", "I wish I could play sports, but I'm just a bot!", "Who's your favorite athlete?", "Sports bring people together!"}},
    {"technology", {"Tech is always evolving!", "AI is changing the world!", "I love talking about gadgets!", "Are you into coding?", "Technology makes life easier!"}},
    {"book", {"Reading is a great way to learn!", "Do you have a favorite book?", "Books open new worlds!", "I wish I could read novels!", "What genre do you enjoy?"}},
    {"travel", {"I'd love to visit new places if I could!", "Do you have a dream travel destination?", "Travel broadens the mind!", "Where was your last trip?", "Exploring new cultures is exciting!"}},
    {"dreams", {"Dream big and make it happen!", "What’s your biggest dream?", "Dreams shape our future!", "It's great to have aspirations!", "Never stop dreaming!"}},
    {"goal", {"Setting goals keeps you motivated!", "What’s your current goal?", "Achieve your dreams step by step!", "Goals give life direction!", "Persistence leads to success!"}},
    {"programming", {"Coding is like magic!", "What's your favorite programming language?", "Programming unlocks endless possibilities!", "Debugging is just another challenge!", "Coding is both fun and frustrating!"}}
};

// Function to convert input to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

// Function to find a response based on keyword matching
char *getResponse(char *input) {
    toLowerCase(input);
    
    for (int i = 0; i < sizeof(database) / sizeof(database[0]); i++) {
        if (strstr(input, database[i].keyword) != NULL) {
            int randIndex = rand() % MAX_RESPONSES; // Random response selection
            return database[i].responses[randIndex];
        }
    }
    return "I'm not sure how to respond to that. Can you try something else?";
}

// Main chatbot function
void chat() {
    char userInput[MAX_INPUT];
    printf("🤖 ChatBot: Hello! Type 'bye' to exit.\n");
    
    while (1) {
        printf("You: ");
        fgets(userInput, MAX_INPUT, stdin);
        userInput[strcspn(userInput, "\n")] = 0; // Remove newline character
        
        if (strcmp(userInput, "bye") == 0) {
            printf("🤖 ChatBot: Goodbye! Have a great day!\n");
            break;
        }
        
        printf("🤖 ChatBot: %s\n", getResponse(userInput));
    }
}

int main() {
    srand(time(NULL)); // Seed the random generator once
    chat();
    return 0;
}
