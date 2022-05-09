

template <typename T>
class BoundCheckIntArray{
	private:
		T* arr;
		int arrlen;
		BoundCheckIntArray(const BoundCheckIntArray& arr){}
		BoundCheckIntArray& operator = (const BoundCheckIntArray& arr) {}
	
	public:
		BoundCheckIntArray(int len) : arrlen(len){
			arr = new int [len];
		}
		int& operator[] (int idx){  // 일반적인 연산자 오버로딩과 동일하다. 리턴값으로 매개변수값을 넣은 배열 값을 한다면 보통의 배열과 다를게 없다. [] 사이에 숫자를 넣는 것이 아니라, [] 다음에 숫자가 있다는 점이 어색하긴 하다.
			if(idx<0 || idx >= arrlen){ // 객체명.operator[] (매개변수) 형태가 된다.
				cout<< "배열 범위 초과" << endl;
				exit(1);
			}
			return arr[idx];
		}
		~BoundCheckIntArray(){
			delete []arr;
		}
};

//위 코드를 통해서 BoundCheckIntArray<int> arr1(50); 을 호출하면 int형 데이터의 저장이 가능하다
// 저장 대상이 Point<int>일 경우엔 BoundCheckIntArray<Point<int>> arr2(50);으로 작성해야한다.
// 저장 대상이 Point<int>*일 경우엔 BoundCheckIntArray<Point<int>*> arr3(40);으로 작성해야한다.