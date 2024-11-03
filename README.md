# PersonalRTOS-Visualizer
A custom Real-Time Operating System (RTOS) Task Scheduler with Visualization in Qt

This project demonstrates a custom implementation of a Real-Time Operating System (RTOS) scheduler, simulating task scheduling and switching using Qt. It features a GUI with real-time visual feedback of task scheduling behavior through progress bars and task states. This RTOS implementation was created from scratch to simulate the basics of task management and preemptive scheduling.

Features

	•	Task Management: Simulate multiple tasks with unique priorities and execution times.
	•	Scheduling Algorithms: Supports preemptive scheduling and round-robin scheduling.
	•	Real-Time Visualization: View task progress, active/inactive states, and task switching in a graphical interface.
	•	Priority-Based Task Switching: Tasks with higher priorities preempt lower-priority tasks.
	•	Custom Implementation: This is an independent implementation, developed specifically for simulation purposes, rather than built on any existing RTOS.

Project Structure

	•	Scheduler: Manages the scheduling of tasks according to priority and preemption rules.
	•	Task: Represents individual tasks with priority, state, and execution time properties.
	•	MainWindow (GUI): Provides a graphical interface to visualize task progress, state changes, and task switching.

Getting Started

Prerequisites

	•	Qt 6.x: This project requires Qt (tested on version 6.7.2) to run the GUI and manage scheduling timers.
	•	C++17: Ensure you have a C++ compiler that supports C++17.

Installation

	1.	Clone this repository to your local machine:
  git clone https://github.com/yourusername/RTOS-Task-Monitor.git
  
	2.	Open the project in Qt Creator.
	3.	Build the Project:
	•	In Qt Creator, load the .pro file.
	•	Select the appropriate kit for your system.
	•	Click Build → Build Project.
	4.	Run the Application: Once built, run the application to view the scheduler in action.

Usage

	1.	Adding Tasks: The application includes a set of default tasks, but you can modify the list of tasks in the MainWindow constructor to experiment with different priority levels and execution times.
	2.	Visualizing Task Scheduling:
	•	The scheduler runs in real-time, displaying each task’s progress.
	•	High-priority tasks will preempt lower-priority tasks, while tasks with the same priority level are scheduled in a round-robin manner.
	3.	Customizing the Scheduler: You can modify the quantum time, preemption rules, and priority handling in the Scheduler class to experiment with different scheduling algorithms.

Code Overview

Main Components

	•	Scheduler:
	•	Manages tasks in a priority queue.
	•	Uses timers to handle task switching and ensure real-time task simulation.
	•	Task:
	•	Encapsulates task attributes such as priority, state (Running, Paused, or Finished), and execution time.
	•	Handles state transitions and updates progress.
	•	MainWindow (GUI):
	•	Displays progress bars with labels for each task.
	•	Updates in real time to reflect the scheduling of tasks and task states.

Example Code Snippets

Creating a Task:
Task* task1 = new Task("Task 1", priority, executionTime);
scheduler->addTask(task1);

Running the Scheduler:
scheduler->start();

Future Enhancements

	•	Support for more scheduling algorithms (e.g., FIFO, EDF).
	•	Dynamic task addition and removal from the GUI.
	•	Additional statistics for monitoring task execution and context switching.

Contributing

Contributions are welcome! Please feel free to open issues or pull requests for any improvements or new features.
