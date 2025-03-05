using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        List<Question> questions = new List<Question>
        {
            new Question("Qual è la capitale d'Italia?", "Roma", new List<string> { "Milano", "Napoli", "Torino" }),
            new Question("Qual è il colore del cielo?", "Blu", new List<string> { "Verde", "Giallo", "Rosso" }),
            new Question("Chi ha scritto 'La Divina Commedia'?", "Dante Alighieri", new List<string> { "Petrarca", "Boccaccio", "Manzoni" })
        };

        int score = 0;
        Random random = new Random();

        Console.WriteLine("Benvenuto al quiz! Rispondi alle domande.");

        foreach (var question in questions)
        {
            Console.WriteLine(question.Text);
            List<string> options = question.GetOptions();
            foreach (var option in options)
            {
                Console.WriteLine(option);
            }

            string answer = Console.ReadLine();
            if (answer.Equals(question.CorrectAnswer, StringComparison.OrdinalIgnoreCase))
            {
                score++;
                Console.WriteLine("Risposta corretta!");
            }
            else
            {
                Console.WriteLine($"Risposta sbagliata! La risposta corretta era: {question.CorrectAnswer}");
            }
        }

        Console.WriteLine($"Hai totalizzato {score} punti su {questions.Count}.");
    }
}

class Question
{
    public string Text { get; }
    public string CorrectAnswer { get; }
    private List<string> IncorrectAnswers { get; }

    public Question(string text, string correctAnswer, List<string> incorrectAnswers)
    {
        Text = text;
        CorrectAnswer = correctAnswer;
        IncorrectAnswers = incorrectAnswers;
    }

    public List<string> GetOptions()
    {
        List<string> options = new List<string> { CorrectAnswer };
        options.AddRange(IncorrectAnswers);
        Shuffle(options);
        return options;
    }

    private void Shuffle(List<string> options)
    {
        Random random = new Random();
        int n = options.Count;
        while (n > 1)
        {
            int k = random.Next(n--);
            var temp = options[n];
            options[n] = options[k];
            options[k] = temp;
        }
    }
}
