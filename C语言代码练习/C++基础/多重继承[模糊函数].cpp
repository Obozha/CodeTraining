#include<iostream>
using namespace std;
class Furniture {
	public:
		Furniture() {

		}
		void SetWeight(int i) {
			weight=i;
		}
		int GetWeight() {
			return weight;
		}
	protected:
		int weight;
};

class Bed:virtual public Furniture {
	public:
		Bed() {
		}
		void Sleep() {
			cout<<"Sleeping"<<endl;
		}
};

class Sofa:virtual public Furniture {
	public:
		Sofa() {
		}

		void WatchTV() {
			cout<<"Watching TV"<<endl;
		}
};

class SleeperSofa:public Bed, public Sofa {
	public:
		SleeperSofa():Sofa(),Bed() {
		}

		void FoldOut() {
			cout<<"Fold out the sofa"<<endl;
		}
};

int main() {
	SleeperSofa ss;
	// ss.SetWeight(20);   // 编译错误！模糊的SetWeight成员
	Sofa sf;
	sf.SetWeight(100);
	cout<<sf.GetWeight()<<endl;
	Furniture* pF;
	//pF=(Furniture*)&ss; // 编译出错！模糊的Furniture
	cout <<ss.GetWeight() <<endl;
}

