```
░▒▓   …/lab/02-student-dll/src   main ?   14:10
❯ gcc main.c functions.c dll.c -o student

░▒▓   …/lab/02-student-dll/src   main ?   14:10
❯ ./student

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 8
The list is empty.

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 1
Enter Student ID: 1
Enter Name: anish
Enter Age: 24
Enter Course: cyber
Enter Marks: 90
Student 1 inserted at the front.

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 2
Enter Student ID: 1
Student with ID 1 already exists.

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 2
Enter Student ID: 2
Enter Name: ram
Enter Age: 23
Enter Course: cyber
Enter Marks: 90
Student 2 inserted at the end.

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 8

ID      Name                Age   Course         Marks
--------------------------------------------------------
1       anish               24    cyber          90.00
2       ram                 23    cyber          90.00

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 3
Enter the position (1 = start): 2
Enter Student ID: 3
Enter Name: jhon
Enter Age: 25
Enter Course: cyber
Enter Marks: 97
Student 3 inserted successfully.

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 8

ID      Name                Age   Course         Marks
--------------------------------------------------------
1       anish               24    cyber          90.00
3       jhon                25    cyber          97.00
2       ram                 23    cyber          90.00

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 7
Enter the first student id: 3
Enter the second student id: 2
Swapped students 3 and 2.

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 8

ID      Name                Age   Course         Marks
--------------------------------------------------------
1       anish               24    cyber          90.00
2       ram                 23    cyber          90.00
3       jhon                25    cyber          97.00

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 6
Enter Student ID to search: 1

ID      Name                Age   Course         Marks
--------------------------------------------------------
1       anish               24    cyber          90.00

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 4
Enter the student id to modify: 1

1. Name
2. Age
3. Course
4. Marks
5. Exit
Enter your choice: 4
Enter the new marks: 85

1. Name
2. Age
3. Course
4. Marks
5. Exit
Enter your choice: 5

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 8

ID      Name                Age   Course         Marks
--------------------------------------------------------
1       anish               24    cyber          85.00
2       ram                 23    cyber          90.00
3       jhon                25    cyber          97.00

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 5
Enter Student ID to delete: 3
Student record deleted successfully.

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 8

ID      Name                Age   Course         Marks
--------------------------------------------------------
1       anish               24    cyber          85.00
2       ram                 23    cyber          90.00

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 10
Invalid choice. Try again.

===== STUDENT DATABASE =====
1. Insert student at front
2. Insert student at end
3. Insert student at a given position
4. Update student
5. Delete student
6. Find student
7. Swap two students
8. Print all students
9. Exit
Enter your choice: 9
Exiting program. Goodbye!

░▒▓   …/lab/02-student-dll/src   main ?   14:21
❯
```
