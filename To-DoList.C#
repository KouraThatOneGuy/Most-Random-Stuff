using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Newtonsoft.Json;

class Program
{
    static string filePath = "tasks.json";
    static List<Task> tasks = new List<Task>();

    static void Main(string[] args)
    {
        LoadTasks();
        string command;

        do
        {
            Console.WriteLine("Enter a command (add, remove, complete, list, exit):");
            command = Console.ReadLine();

            switch (command.ToLower())
            {
                case "add":
                    AddTask();
                    break;
                case "remove":
                    RemoveTask();
                    break;
                case "complete":
                    CompleteTask();
                    break;
                case "list":
                    ListTasks();
                    break;
            }
        } while (command != "exit");

        SaveTasks();
    }

    static void LoadTasks()
    {
        if (File.Exists(filePath))
        {
            var json = File.ReadAllText(filePath);
            tasks = JsonConvert.DeserializeObject<List<Task>>(json) ?? new List<Task>();
        }
    }

    static void SaveTasks()
    {
        var json = JsonConvert.SerializeObject(tasks, Formatting.Indented);
        File.WriteAllText(filePath, json);
    }

    static void AddTask()
    {
        Console.WriteLine("Enter task description:");
        var description = Console.ReadLine();
        tasks.Add(new Task { Description = description, IsComplete = false });
    }

    static void RemoveTask()
    {
        Console.WriteLine("Enter task number to remove:");
        int index = int.Parse(Console.ReadLine()) - 1;
        if (index >= 0 && index < tasks.Count)
        {
            tasks.RemoveAt(index);
        }
    }

    static void CompleteTask()
    {
        Console.WriteLine("Enter task number to mark as complete:");
        int index = int.Parse(Console.ReadLine()) - 1;
        if (index >= 0 && index < tasks.Count)
        {
            tasks[index].IsComplete = true;
        }
    }

    static void ListTasks()
    {
        for (int i = 0; i < tasks.Count; i++)
        {
            var status = tasks[i].IsComplete ? "[X]" : "[ ]";
            Console.WriteLine($"{i + 1}. {status} {tasks[i].Description}");
        }
    }
}

class Task
{
    public string Description { get; set; }
    public bool IsComplete { get; set; }
}
