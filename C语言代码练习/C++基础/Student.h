class Student{
	protected:
		char name[40];
	public:
		static int noOfStudents; // 静态数据成员声明
		Student(char *pName="no name");
		~Student();
		static int number(); // 静态成员函数声明		 
}; 
