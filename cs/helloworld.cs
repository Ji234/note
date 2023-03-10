using System;

namespace c.biancheng.net
{
    class Demo
    {
        static void Main(string[] args) 
        {
            // Student stu = new Student();
            Student.id = 101;
            Student.name = "张三";
            Student.Display();
            Console.Read();
        }
    }
    public class Student
    {
        private Student() { }
        public static int id;
        public static string name;
        public static void Display()
        {
            Console.WriteLine("姓名："+name+" 编号："+id);
        }
    }
}