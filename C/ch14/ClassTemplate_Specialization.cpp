template <typename T>

class SoSimple{
	public:
		T SimpleFun(T num){}
};

//자료형 int에 대해 특수화 한 템플릿 클래스는 다음과 같이 정의한다.

template <>
class SoSimple<int>{
	public:
		int SimpleFun(int num){}
};

//객체 생성할 때도 SoSimple<int> obj; 로 호출해야한다.



//template <typename T= int, int len = 7>처럼 작성할 경우 디폴트 값이 되버린 것이다.