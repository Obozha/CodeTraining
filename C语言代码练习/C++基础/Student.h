class Student{
	protected:
		char name[40];
	public:
		static int noOfStudents; // ��̬���ݳ�Ա����
		Student(char *pName="no name");
		~Student();
		static int number(); // ��̬��Ա��������		 
}; 
