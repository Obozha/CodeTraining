class Point{
	public:
		Point(double ix,double iy){
			x=ix;
			y=iy;
		}
		void Set(double ix,double iy); // ��������
		double xOffset(); // ֱ������x����
		double yOffset(); // ֱ������y����
		double angle();   // �����껡��
		double radius();  // ������뾶
	protected:
		double x;		  // ֱ�������ֻ����� 
		double y; 
};
