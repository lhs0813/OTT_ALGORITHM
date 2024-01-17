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

	//�Ҵ� �迭 �ڵ�
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
	

	char number; //��ȭ���� �Է�
	string movie_choose;
	string movie_list[19] = 
	{ 
		"�׼�, SF, ����, �̱�, �δ���", // ����� 1
		"�׼�, ����, SF, �̱�, ��Ȧ����, �δ���", //�����̴���: �����Ȩ
		"�׼�, SF, ����, �̱�, �߱�, �δ���", //���̾�� 3

		"�׼�, �и��͸�, ���, �̱�, ��ũ����",//ž�� 
		"����, �׼�, �ڹ̵�, �̱�, ��ũ����", // �Ƹ޸�ĭ ���̵�
		"SF, ���, �׼�, �̱�, ��ũ����", // ���̳ʸ�Ƽ ����Ʈ

		"����, ȣ��, ������, �̱�, ���� �Ĺ̰�",// ������
		"����, �̽��͸�, ������, �ѱ�, ������", // ������
		"����, �̽��͸�, ������, �̱�, �ٴϿ�", // �پƿ�

		"���, �θǽ�, ���, �̱�, L.D",//Ÿ��Ÿ��
		"���, �θǽ�, ���, �븸, �ְɷ�", //���Ҽ� ���� ���
		"���, �θǽ�, ���, �ѱ�, ����", // �����а���

		"����, �׼�, ���, �ѱ�, ������", //����Ȳ��
		"�׼�, ������, ����, �ѱ�, ������", //�λ���
		"���, �ڹ̵�, û��, �ѱ�, ������", //�õ�

		"�ִϸ��̼�, ����, ����, �̱�, ����", //�ܿ�ձ�
		"�ִϸ��̼�, �ڹ̵�, ����, �Ϻ�, ¯��", //�Ұ��ε�
		"�ִϸ��̼�, ����, �ڹ̵�, �Ϻ�, ���󿡸�"// ���󿡸�������
	};

	string movie_name[19] =
	{
		"����� 1", // ����� 1
		"�����̴���: �����Ȩ", //�����̴���: �����Ȩ
		"���̾�� 3", //���̾�� 3

		"ž��",//ž�� 
		"�Ƹ޸�ĭ ���̵�", // �Ƹ޸�ĭ ���̵�
		"���̳ʸ�Ƽ ����Ʈ", // ���̳ʸ�Ƽ ����Ʈ

		"������",// ������
		"������", // ������
		"�پƿ�", // �پƿ�

		"Ÿ��Ÿ��",//Ÿ��Ÿ��
		"���Ҽ� ���� ���", //���Ҽ� ���� ���
		"�����а���", // �����а���

		"����Ȳ��", //����Ȳ��
		"�λ���", //�λ���
		"�õ�", //�õ�

		"�ܿ�ձ�", //�ܿ�ձ�
		"�Ұ��ε�", //�Ұ��ε�
		"���󿡸�������"// ���󿡸�������
	};

	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� " << endl;
	cout << "| ��ȭ ��õ ���α׷� �Դϴ�.                                                           |" << endl;
	cout << "| ����Ʈ�� Ȯ���Ͻð�, ������ ����ְ� ���Ҵ� ��ȭ�� ������ �ּ���.                    |" << endl;
	cout << "| 1. �̼����ļ��� 5                                                                    |" << endl;
	cout << "| 2. ����� 2                                                                        |" << endl;
	cout << "| 3. �νõ� 2                                                                      |" << endl;
	cout << "| 4. ���˵���                                                                          |" << endl;
	cout << "| 5. ��ٿ� Ÿ��                                                                       |" << endl;
	cout << "| 6. �ָԿ� ����                                                                       |" << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� " << endl;

	
	cin >> number;

	switch (number)
	{
	case '1':
		cout << "�̼� ���ļ��� 5�� �����ϼ̽��ϴ�." << endl;
		cout << "�ش� ��ȭ�� ������, ��ȭ�� ��õ�� �帮�ڽ��ϴ�." << endl;
		movie_choose = "�׼�, ����, ������, �̱�, ��ũ����";
		break;
	case '2':
		cout << "����� 2 �� �����ϼ̽��ϴ�." << endl;
		cout << "�ش� ��ȭ�� ������, ��ȭ�� ��õ�� �帮�ڽ��ϴ�." << endl;
		movie_choose = "�׼�, ��Ÿ��, SF, �̱�, �δ���";
		break;
	case '3':
		cout << "�νõ� 2 �� �����ϼ̽��ϴ�." << endl;
		cout << "�ش� ��ȭ�� ������, ��ȭ�� ��õ�� �帮�ڽ��ϴ�." << endl;
		movie_choose = "����, ������, �̽��͸�, �̱�, ���� ��";
		break;
	case '4':
		cout << "���˵��� �� �����ϼ̽��ϴ�." << endl;
		cout << "�ش� ��ȭ�� ������, ��ȭ�� ��õ�� �帮�ڽ��ϴ�." << endl;
		movie_choose = "����, �׼�, �ڹ̵�, �ѱ�, ������";
		break;
	case '5':
		cout << "��ٿ� Ÿ��  �� �����ϼ̽��ϴ�." << endl;
		cout << "�ش� ��ȭ�� ������, ��ȭ�� ��õ�� �帮�ڽ��ϴ�." << endl;
		movie_choose = "���, �θǽ�, �ڹ̵�, ����, ����ÿ";
		break;
	case '6':
		cout << "�ָԿ� ����  �� �����ϼ̽��ϴ�." << endl;
		cout << "�ش� ��ȭ�� ������, ��ȭ�� ��õ�� �帮�ڽ��ϴ�." << endl;
		movie_choose = "�ִϸ��̼�, ����, �ڹ̵�, �̱�, ����";
		break;
	}

	cout << "�ش� ��ȭ�� ���� ���絵�� �����մϴ�." << endl;

	double score[19];
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� " << endl;
	for (int i = 0; i < 19; i++) {
		score[i] = findStringSimilarity(movie_choose, movie_list[i]);
	}
	float _100pe;
	for (int i = 0; i < 18; i++) {

		cout.precision(3);
		_100pe = score[i];
		_100pe = _100pe * 100;
		cout << i +1 <<". " <<movie_name[i] <<". ���� : " << _100pe << "%" << endl;

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
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� " << endl;
	cout << "\n";
	cout << "��õ�ϴ� ��ȭ�� : " << movie_name[j] <<" �Դϴ�." <<endl;
	cout << "��ſ� ���� �ǽñ� �ٶ��ϴ�!!"<< endl;


	

	/*double similarity = findStringSimilarity(movie_choose, movie_list[1]);

	std::cout <<"�� ���� ���� ���絵�� " <<  similarity;
	cout << '\n';*/
}


