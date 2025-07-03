# Student Management System

A simple console-based Student Management System written in C that allows you to manage student records with persistent file storage.

## Features

- **View All Students**: Display all student records with their complete information
- **Add Student**: Add new student records to the system
- **Delete Student**: Remove student records by ID
- **Update Student**: Modify existing student information
- **Persistent Storage**: All data is stored in a text file (`logs.txt`)

## Student Information Stored

Each student record contains:
- Student ID
- Full Name
- Semester
- Section
- Department
- Total Classes
- Classes Attended
- Attendance Percentage (automatically calculated)
- CGPA

## Prerequisites

- C Compiler (GCC, MinGW, or any C compiler)
- Windows Operating System (uses `system("cls")` for screen clearing)

## Installation and Setup

1. **Clone or Download** the project files
2. **Compile** the program:
   ```powershell
   gcc student_management_system.c -o student_management_system.exe
   ```
3. **Run** the executable:
   ```powershell
   .\student_management_system.exe
   ```

## How to Use

### Main Menu Options

When you run the program, you'll see a menu with the following options:

```
1. View all students
2. Add a student information
3. Delete a student information
4. Update a student information
5. Exit
```

### 1. View All Students
- Displays all student records stored in the system
- Shows complete information for each student including calculated attendance percentage

### 2. Add a Student
- Prompts you to enter all student information
- Automatically calculates attendance percentage based on total classes and classes attended
- Saves the new student record to the file

### 3. Delete a Student
- Prompts for student ID
- Removes the student record if found
- Updates the file with remaining records

### 4. Update a Student
- Prompts for student ID to identify the record to update
- Allows you to update specific fields:
  - Name
  - Section
  - Department
  - CGPA
  - Semester
- Saves the updated information to the file

### 5. Exit
- Safely exits the program

## File Structure

```
├── student_management_system.c    # Main source code
├── student_management_system.exe  # Compiled executable
├── logs.txt                       # Data storage file (created automatically)
└── README.md                      # This file
```

## Data Storage

- Student data is stored in `logs.txt` in a structured format
- The file is automatically created if it doesn't exist
- Each student's information is stored on separate lines in a specific order

## Sample Usage

1. **Adding a Student:**
   ```
   Enter your ID: 2021001
   Enter your Name: John Doe
   Enter your semester: 3
   Enter your Section: A
   Enter your Department: Computer Science
   Enter the number of your total class: 50
   Enter the number of your present: 45
   Enter your CGPA: 3.75
   ```

2. **Updating a Student:**
   - Enter the student ID
   - Choose what to update (Name, Section, Department, CGPA, or Semester)
   - Enter the new value

## Notes

- Student IDs should be unique
- Attendance percentage is automatically calculated as: (Present Classes / Total Classes) × 100
- The program uses console clearing (`cls`) which works on Windows systems
- All data is persistent and will be available when you restart the program

## Limitations

- Maximum of 100 students can be stored (array size limitation)
- No data validation for input formats
- Windows-specific console commands
- No backup mechanism for data file

## Future Enhancements

- Add input validation
- Implement search functionality
- Add sorting options
- Create backup mechanisms
- Add cross-platform compatibility
- Implement data encryption for sensitive information

## Contributing

Feel free to fork this project and submit pull requests for any improvements or bug fixes.

## License

This project is open source and available under the MIT License.
