#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int getEditDistance(std::string first, std::string second)
{
	int m = first.length();
	int n = second.length();

	int cnt = 0;

	//할당 배열 코드
	int** T = new int* [m+1];
	for (int i = 0; i < m+1; ++i) {
		T[i] = new int[n+1];
	}


	for (int i = 0; i < m; i++) {
		for(int j=0; j<n; j++) {			
			T[i][j] = cnt++;		
		}	
	}

	/*for (int i = 0; i < m; i++) {
		for(int j=0; j<n; j++) {			
			cout<<T[i][j]<<",";		
		}		
		cout<<'\n';	
	}*/
		
	/*cout << '\n';*/


	for (int i = 1; i <= m; i++) {
		T[i][0] = i;
	}

	for (int j = 1; j <= n; j++) {
		T[0][j] = j;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int weight = first[i - 1] == second[j - 1] ? 0 : 1;
			T[i][j] = std::min(std::min(T[i - 1][j] + 1, T[i][j - 1] + 1), T[i - 1][j - 1] + weight);
		}
	}

	return T[m][n];
}

double findStringSimilarity(std::string first, std::string second) {
	double max_length = std::max(first.length(), second.length());
	if (max_length > 0) {
		return (max_length - getEditDistance(first, second)) / max_length;
	}
	return 1.0;
}

class movie {
	movie(string movie1, string movie2);
};

int main() {
	

	char number; //영화선택 입력
	string movie_choose;
	string movie_list[19] = 
	{ 
		"액션, SF, 모험, 미국, 로다주", // 어벤져스 1
		"액션, 모험, SF, 미국, 톰홀랜드, 로다주", //스파이더맨: 노웨이홈
		"액션, SF, 모험, 미국, 중국, 로다주", //아이언맨 3

		"액션, 밀리터리, 드라마, 미국, 톰크루즈",//탑건 
		"범죄, 액션, 코미디, 미국, 톰크루즈", // 아메리칸 메이드
		"SF, 드라마, 액션, 미국, 톰크루즈", // 마이너리티 리포트

		"공포, 호러, 스릴러, 미국, 베라 파미가",// 컨저링
		"공포, 미스터리, 스릴러, 한국, 위하준", // 곤지암
		"공포, 미스터리, 스릴러, 미국, 다니엘", // 겟아웃

		"멜로, 로맨스, 드라마, 미국, L.D",//타이타닉
		"멜로, 로맨스, 드라마, 대만, 주걸륜", //말할수 없는 비밀
		"멜로, 로맨스, 드라마, 한국, 수지", // 건축학개론

		"범죄, 액션, 드라마, 한국, 마동석", //성난황소
		"액션, 스릴러, 좀비, 한국, 마동석", //부산행
		"드라마, 코미디, 청춘, 한국, 마동석", //시동

		"애니메이션, 모험, 가족, 미국, 엘사", //겨울왕국
		"애니메이션, 코미디, 가족, 일본, 짱구", //불고기로드
		"애니메이션, 모험, 코미디, 일본, 도라에몽"// 도라에몽극장판
	};

	string movie_name[19] =
	{
		"어벤져스 1", // 어벤져스 1
		"스파이더맨: 노웨이홈", //스파이더맨: 노웨이홈
		"아이언맨 3", //아이언맨 3

		"탑건",//탑건 
		"아메리칸 메이드", // 아메리칸 메이드
		"마이너리티 리포트", // 마이너리티 리포트

		"컨저링",// 컨저링
		"곤지암", // 곤지암
		"겟아웃", // 겟아웃

		"타이타닉",//타이타닉
		"말할수 없는 비밀", //말할수 없는 비밀
		"건축학개론", // 건축학개론

		"성난황소", //성난황소
		"부산행", //부산행
		"시동", //시동

		"겨울왕국", //겨울왕국
		"불고기로드", //불고기로드
		"도라에몽극장판"// 도라에몽극장판
	};

	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ " << endl;
	cout << "| 영화 추천 프로그램 입니다.                                                           |" << endl;
	cout << "| 리스트를 확인하시고, 본인이 재미있게 보았던 영화를 선택해 주세요.                    |" << endl;
	cout << "| 1. 미션임파서블 5                                                                    |" << endl;
	cout << "| 2. 어벤져스 2                                                                        |" << endl;
	cout << "| 3. 인시디어스 2                                                                      |" << endl;
	cout << "| 4. 범죄도시                                                                          |" << endl;
	cout << "| 5. 어바웃 타임                                                                       |" << endl;
	cout << "| 6. 주먹왕 랄프                                                                       |" << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ " << endl;

	
	cin >> number;

	switch (number)
	{
	case '1':
		cout << "미션 임파서블 5를 선택하셨습니다." << endl;
		cout << "해당 영화와 유사한, 영화를 추천해 드리겠습니다." << endl;
		movie_choose = "액션, 모험, 스릴러, 미국, 톰크루즈";
		break;
	case '2':
		cout << "어벤져스 2 를 선택하셨습니다." << endl;
		cout << "해당 영화와 유사한, 영화를 추천해 드리겠습니다." << endl;
		movie_choose = "액션, 판타지, SF, 미국, 로다주";
		break;
	case '3':
		cout << "인시디어스 2 를 선택하셨습니다." << endl;
		cout << "해당 영화와 유사한, 영화를 추천해 드리겠습니다." << endl;
		movie_choose = "공포, 스릴러, 미스터리, 미국, 로즈 번";
		break;
	case '4':
		cout << "범죄도시 를 선택하셨습니다." << endl;
		cout << "해당 영화와 유사한, 영화를 추천해 드리겠습니다." << endl;
		movie_choose = "범죄, 액션, 코미디, 한국, 마동석";
		break;
	case '5':
		cout << "어바웃 타임  를 선택하셨습니다." << endl;
		cout << "해당 영화와 유사한, 영화를 추천해 드리겠습니다." << endl;
		movie_choose = "멜로, 로맨스, 코미디, 영국, 레이첼";
		break;
	case '6':
		cout << "주먹왕 랄프  를 선택하셨습니다." << endl;
		cout << "해당 영화와 유사한, 영화를 추천해 드리겠습니다." << endl;
		movie_choose = "애니메이션, 가족, 코미디, 미국, 랄프";
		break;
	}

	cout << "해당 영화를 통해 유사도를 측정합니다." << endl;

	double score[19];
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ " << endl;
	for (int i = 0; i < 19; i++) {
		score[i] = findStringSimilarity(movie_choose, movie_list[i]);
	}
	float _100pe;
	for (int i = 0; i < 18; i++) {

		cout.precision(3);
		_100pe = score[i];
		_100pe = _100pe * 100;
		cout << i +1 <<". " <<movie_name[i] <<". 점수 : " << _100pe << "%" << endl;

	}

	//sort(score, score + 19, greater<>());
	
	int max = 0;
	int j = 0.0;
	for (int i = 1; i < 19; i++) {
		if (score[max] < score[i]) {
			max = i;
			j = i;
		}
	}
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ " << endl;
	cout << "\n";
	cout << "추천하는 영화는 : " << movie_name[j] <<" 입니다." <<endl;
	cout << "즐거운 관람 되시길 바랍니다!!"<< endl;


	

	/*double similarity = findStringSimilarity(movie_choose, movie_list[1]);

	std::cout <<"두 문장 간의 유사도는 " <<  similarity;
	cout << '\n';*/
}


