template <typename T>
T Max(T a, T b){
	return a > b ? a : b;
}

template<>  //char* 형 함수는 내가 제시할 테니 char* 형 템플릿 함수가 필요하다면 별도로 만들지 말고 이걸 써라!
char* Max(char* a, char* b){
	return strlen(a) > strlen(b) ? a : b;
}

template<>
const char* Max(const char* a, const char* b){
	return strcmp(a,b) > 0 : a : b;
}

