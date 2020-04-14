package java_project.employees;

public final class Worker implements Employee {
    protected int salary;
    protected String name;
    public int employeeId;
    public Worker(String name, int Id)
    {
        this.employeeId = Id;
        this.name = name;
        salary = 1000;
    }
    public void increment(final int percent) // formal parameter
    {
        final int bonus = 100; // local parameter
        salary += (salary * percent / 100) + bonus;
    }
    public String toString() 
    {
        return "[ EmpID :" + employeeId + ",\t name : " + name + ",\t salary : " + salary + "]";
    }

}