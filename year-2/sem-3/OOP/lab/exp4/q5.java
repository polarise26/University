// Q5
// Design a class employee of an organization. An employee has a name, empid, and salary. Write the default constructor, a constructor with parameters (name, empid, and salary) and methods to return name and salary. Also write a method increaseSalary that raises the employee’s salary by a certain user specified percentage. Derive a subclass Manager from employee. Add an instance variable named department to the manager class. Supply a test program that uses theses classes and methods.   

class Employee {
    private String name;
    private String empid;
    private double salary;

    public Employee() {
    }

    public Employee(String name, String empid, double salary) {
        this.name = name;
        this.empid = empid;
        this.salary = salary;
    }

    public String getName() {
        return this.name;
    }

    public double getSalary() {
        return this.salary;
    }

    public void increaseSalary(double increaseBy) {
        increaseBy /= 100;
        this.salary += this.salary * increaseBy;
    }
}

class Manager extends Employee {
    private String department;

    public Manager() {
    };
}

public class q5 {
    public static void main(String[] args) {
        // Employee E1 = new Employee("E1", "500081889", 100);
        // System.out.println(E1.getName());
        // System.out.println(E1.getSalary());

    }
}
