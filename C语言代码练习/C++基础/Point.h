class Point{
	public:
		Point(double ix,double iy){
			x=ix;
			y=iy;
		}
		void Set(double ix,double iy); // 设置坐标
		double xOffset(); // 直角坐标x分量
		double yOffset(); // 直角坐标y分量
		double angle();   // 极坐标弧角
		double radius();  // 极坐标半径
	protected:
		double x;		  // 直角坐标抑或极坐标 
		double y; 
};
