import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

abstract class Employee
{
    public int employeeId;  //global parameter
    protected String name;
    public int salary;
    static String companyName = "Haayka Softwares";
    static int employeeIdGenerator = 0;
    public abstract void increment(int percent); //formal parameter
    public String toString() 
    {
        return "[ EmpID :" + employeeId + ",\t name : " + name + ",\t salary : " + salary + "]";
    }
    
}

class Worker extends Employee
{
    Worker(final String name) {
        employeeId = ++employeeIdGenerator;
        this.name = name;
        salary = 1000;
    }

    public void increment(final int percent) // formal parameter
    {
        final int bonus = 100; // local parameter
        salary += (salary * percent / 100) + bonus;
    }
}

class Manager extends Employee {
    Manager(final String name) {
        employeeId = ++employeeIdGenerator;
        this.name = name;
        salary = 2000;
    }

    public void increment(final int percent) {
        final int bonus = 200;
        salary += (salary * percent / 100) + bonus;
    }
}

public class assignment10 {
    public static void main(final String[] args) {
        final Scanner input = new Scanner(System.in);
        String name;
        int choice, percent, Id;
        final List<Worker> workers = new ArrayList<Worker>();
        final List<Manager> managers = new ArrayList<Manager>();
        while (true) {

            System.out.println("\n*********** Wel-Come to " + Employee.companyName + " *************");
            System.out.println("    1. Register an Employee");
            System.out.println("    2. Increment Salary of an Employee");
            System.out.println("    3. Show Employees of " + Employee.companyName);
            System.out.print("    4. Enter your choice :: ");
            choice = input.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("");
                    System.out.println("        1. Worker");
                    System.out.println("        2. Manager");
                    System.out.print("        Select Employee Type ::");
                    choice = input.nextInt();
                    switch (choice) {
                        case 1:
                            System.out.print("Enter Name :: ");
                            name = input.nextLine(); // nextLine() has unexpected behaviour, we need to add an extra
                                                     // nextLine()
                            name = input.nextLine();
                            workers.add(new Worker(name));
                            break;
                        case 2:
                            System.out.print("Enter Name :: ");
                            name = input.nextLine(); // nextLine() has unexpected behaviour, we need to add an extra
                                                     // nextLine()
                            name = input.nextLine();
                            managers.add(new Manager(name));
                            break;
                    }
                    for (final Worker data : workers) {
                        System.out.println(data);
                    }
                    for (final Manager data : managers) {
                        System.out.println(data);
                    }

                    break;

                case 2:
                    System.out.println("");
                    System.out.println("        1. Worker");
                    System.out.println("        2. Manager");
                    System.out.print("        Select Employee Type ::");
                    choice = input.nextInt();
                    switch (choice) {
                        case 1:
                            for (final Worker worker : workers) {
                                System.out.println(worker);
                            }

                            System.out.print("Enter Employee ID :: ");
                            Id = input.nextInt();

                            for (final Worker worker : workers) {
                                if (worker.employeeId == Id) {
                                    System.out.print("Enter Increment % :: ");
                                    percent = input.nextInt();
                                    worker.increment(percent);
                                    break;
                                }
                            }
                            break;

                        case 2:
                            for (final Manager manager : managers) {
                                System.out.println(manager);
                            }
                            System.out.print("Enter Employee ID :: ");
                            Id = input.nextInt();
                            for (final Manager manager : managers) {
                                if (manager.employeeId == Id) {
                                    System.out.print("Enter Increment % :: ");
                                    percent = input.nextInt();
                                    manager.increment(percent);
                                    break;
                                }
                            }
                            break;
                    }
                    System.out.println("::::: Workers :::::");
                    for (final Worker worker : workers) {
                        System.out.println(worker);
                    }
                    System.out.println("::::: Managers :::::");
                    for (final Manager manager : managers) {
                        System.out.println(manager);
                    }
                    break;

                case 3:
                    System.out.println("::::: Workers :::::");
                    for (final Worker worker : workers) {
                        System.out.println(worker);
                    }
                    System.out.println("::::: Managers :::::");
                    for (final Manager manager : managers) {
                        System.out.println(manager);
                    }
                default:
                    break;                
            }   
        }
        //input.close();
    }
}