using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        Quiz quiz = new Quiz();
        quiz.Start();
    }
}

class Quiz
{
    private List<Question> questions;
    private int score;

    public Quiz()
    {
        questions = new List<Question>
        {
            new Question("What is the capital of France?", "Paris", 1),
            new Question("What is 2 + 2?", "4", 1),
            new Question("What is the largest planet in our solar system?", "Jupiter", 2),
            new Question("What is the square root of 144?", "12", 2),
            new Question("What is the chemical symbol for gold?", "Au", 3),
            new Question("What is the speed of light?", "299792458 m/s", 3)
        };
        score = 0;
    }

    public void Start()
    {
        Console.WriteLine("Welcome to the Dynamic Quiz!");
        Random rand = new Random();
        foreach (var question in questions)
        {
            if (rand.Next(1, 4) <= question.Difficulty)
            {
                AskQuestion(question);
            }
        }
        Console.WriteLine($"Your final score is: {score}");
    }

    private void AskQuestion(Question question)
    {
        Console.WriteLine(question.Text);
        string answer = Console.ReadLine();
        if (answer.Equals(question.Answer, StringComparison.OrdinalIgnoreCase))
        {
            Console.WriteLine("Correct!");
            score++;
        }
        else
        {
            Console.WriteLine($"Wrong! The correct answer is: {question.Answer}");
        }
    }
}

class Question
{
    public string Text { get; }
    public string Answer { get; }
    public int Difficulty { get; }

    public Question(string text, string answer, int difficulty)
    {
        Text = text;
        Answer = answer;
        Difficulty = difficulty;
    }
}
