#include "chess.h"

//��ʼ������
void InitBoard(char board[][COL], int row, int col){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			board[i][j] = ' ';
		}
	}
}

//����һ��
int playerMove(char board[][COL], int row, int col){
	int x = 0;
	int y = 0;
	printf("Pllease Enter Your Pos<x, y># ");
	scanf("%d %d", &x, &y);
	if (x >= 1 && x <= 3 && y >= 1 && y <= 3){
		if (board[x - 1][y - 1] != ' '){
			return 2;	//�û����걻ռ��
		}
		board[x - 1][y - 1] = BLACK_PIECE;	//��������ӵ�������
		return 0;
	}
	return 1;	//�û�������������
}

//��ʾ�������
void showBoard(char board[][COL], int row, int col){
	printf("   | 1 | 2 | 3 |\n");
	for (int i=1; i<=row; i++){
		printf("----------------\n");
		printf(" %d | %c | %c | %c |\n", i, board[i-1][0], board[i-1][1], board[i-1][2]);
	}
	printf("----------------\n");
}

//�û�Ӯ��	BLACK_PIECE	'��'
//����Ӯ��	WHITE_PIECE	'��'
//ƽ��	'E'
//��ûӮ������	'N'
char JudgeResult(char board[][COL], int row, int col){
	//�ж����Ƿ����
	for (int i = 0; i < row; i++){
		if (board[i][0]!=' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
			return board[i][0];
		}
	}

	//�ж����Ƿ����
	for (int i = 0; i < col; i++){
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
			return board[0][i];
		}
	}

	//�ж϶Խ����Ƿ����
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
		return board[0][0];
	}
	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
		return board[0][2];
	}

	//�ж��Ƿ�û�н��
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (board[i][j] == ' '){
				return 'N';
			}
		}
	}

	return 'E';
}

//����������һ��
void ComputerMove(char board[][COL], int row, int col){
	while (1){
		int i = rand() % row;	// 0-2֮��
		int j = rand() % col;	// 0-2֮��

		if (board[i][j] == ' '){
			board[i][j] = WHITE_PIECE;
			break;
		}
	}
	printf("Computer ... Done\n");
	Sleep(1000);
}

//�㷨�ж�
//difference�����м��͸߼�����
int algorithm(char board[][COL], int row, int col, int difference){
	if (difference){
		//��Ҫ�ж��Լ��ܷ��ʤ
		//�ж���
		for (int i = 0; i < 3; i++){
			if (board[i][0] == WHITE_PIECE && board[i][1] == WHITE_PIECE){
				if (board[i][2] == ' '){
					board[i][2] = WHITE_PIECE;
					return 1;
				}
			}
			else if (board[i][0] == WHITE_PIECE && board[i][2] == WHITE_PIECE){
				if (board[i][1] == ' '){
					board[i][1] = WHITE_PIECE;
					return 1;
				}
			}
			else if (board[i][1] == WHITE_PIECE && board[i][2] == WHITE_PIECE){
				if (board[i][0] == ' '){
					board[i][0] = WHITE_PIECE;
					return 1;
				}
			}
		}

		//�ж���
		for (int i = 0; i < 3; i++){
			if (board[0][i] == WHITE_PIECE && board[1][i] == WHITE_PIECE){
				if (board[2][i] == ' '){
					board[2][i] = WHITE_PIECE;
					return 1;
				}
			}
			else if (board[0][i] == WHITE_PIECE && board[2][i] == WHITE_PIECE){
				if (board[1][i] == ' '){
					board[1][i] = WHITE_PIECE;
					return 1;
				}
			}
			else if (board[1][i] == WHITE_PIECE && board[2][i] == WHITE_PIECE){
				if (board[0][i] == ' '){
					board[0][i] = WHITE_PIECE;
					return 1;
				}
			}
		}

		//�ж϶Խ���
		if (board[0][0] == WHITE_PIECE&&board[1][1] == WHITE_PIECE){
			if (board[2][2] == ' '){
				board[2][2] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[0][0] == WHITE_PIECE&&board[2][2] == WHITE_PIECE){
			if (board[1][1] == ' '){
				board[1][1] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[1][1] == WHITE_PIECE&&board[2][2] == WHITE_PIECE){
			if (board[0][0] == ' '){
				board[0][0] = WHITE_PIECE;
				return 1;
			}
		}
		//�ж϶Խ���
		if (board[0][2] == WHITE_PIECE&&board[1][1] == WHITE_PIECE){
			if (board[2][0] == ' '){
				board[2][0] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[0][2] == WHITE_PIECE&&board[2][0] == WHITE_PIECE){
			if (board[1][1] == ' '){
				board[1][1] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[2][0] == WHITE_PIECE&&board[1][1] == WHITE_PIECE){
			if (board[0][2] == ' '){
				board[0][2] = WHITE_PIECE;
				return 1;
			}
		}
	}

	//����Ǹ߼������ˣ��ж��Լ����ܻ�ʤ�����ж��Լ��Ƿ���Ҫ��ס���
	//�ж���
	for (int i = 0; i < 3; i++){
		if (board[i][0] == BLACK_PIECE && board[i][1] == BLACK_PIECE){
			if (board[i][2] == ' '){
				board[i][2] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[i][0] == BLACK_PIECE && board[i][2] == BLACK_PIECE){
			if (board[i][1] == ' '){
				board[i][1] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[i][1] == BLACK_PIECE && board[i][2] == BLACK_PIECE){
			if (board[i][0] == ' '){
				board[i][0] = WHITE_PIECE;
				return 1;
			}
		}
	}

	//�ж���
	for (int i = 0; i < 3; i++){
		if (board[0][i] == BLACK_PIECE && board[1][i] == BLACK_PIECE){
			if (board[2][i] == ' '){
				board[2][i] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[0][i] == BLACK_PIECE && board[2][i] == BLACK_PIECE){
			if (board[1][i] == ' '){
				board[1][i] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[1][i] == BLACK_PIECE && board[2][i] == BLACK_PIECE){
			if (board[0][i] == ' '){
				board[0][i] = WHITE_PIECE;
				return 1;
			}
		}
	}

	//�ж϶Խ���
	if (board[0][0] == BLACK_PIECE&&board[1][1] == BLACK_PIECE){
		if (board[2][2] == ' '){
			board[2][2] = WHITE_PIECE;
			return 1;
		}
	}
	else if (board[0][0] == BLACK_PIECE&&board[2][2] == BLACK_PIECE){
		if (board[1][1] == ' '){
			board[1][1] = WHITE_PIECE;
			return 1;
		}
	}
	else if (board[1][1] == BLACK_PIECE&&board[2][2] == BLACK_PIECE){
		if (board[0][0] == ' '){
			board[0][0] = WHITE_PIECE;
			return 1;
		}
	}
	//�ж϶Խ���
	if (board[0][2] == BLACK_PIECE&&board[1][1] == BLACK_PIECE){
		if (board[2][0] == ' '){
			board[2][0] = WHITE_PIECE;
			return 1;
		}
	}
	else if (board[0][2] == BLACK_PIECE&&board[2][0] == BLACK_PIECE){
		if (board[1][1] == ' '){
			board[1][1] = WHITE_PIECE;
			return 1;
		}
	}
	else if (board[2][0] == BLACK_PIECE&&board[1][1] == BLACK_PIECE){
		if (board[0][2] == ' '){
			board[0][2] = WHITE_PIECE;
			return 1;
		}
	}

	//������жԽ��߶������㣬����0���������ֵ
	return 0;
}

//�м�������һ��
void middleComputerMove(char board[][COL], int row, int col){
	//�㷨�жϣ����Ҫ��ס��ң�������ס��ң�����1���������Ҫ���������һ��
	int flag = algorithm(board, ROW, COL,0);

	//���õ����жϣ���û����һ�л��л�Խ�����������BLACK_PIECE������У�����1�����û�У��ͷ���-1��������һ�л��л�Խ��߶�ס��
	if (flag){
			
	}

	while (!flag){
		int i = rand() % row;	//0-2֮��
		int j = rand() % col;	//0-2֮��

		

		if (board[i][j] == ' '){
			board[i][j] = WHITE_PIECE;
			break;
		}
	}
	printf("Computer ... Done\n");
	Sleep(1000);
}

//�߼�������һ��
void seniorComputerMove(char board[][COL], int row, int col){
	//�㷨�жϣ����ж��Լ��ܷ��ʤ�����ж��Ƿ���Ҫ��ס��ң�������ס��ң�����1���������Ҫ���������һ��
	int flag = algorithm(board, ROW, COL, 1);

	//���õ����жϣ���û����һ�л��л�Խ�����������BLACK_PIECE������У�����1�����û�У��ͷ���-1��������һ�л��л�Խ��߶�ס��
	if (flag){

	}

	while (!flag){
		int i = rand() % row;	//0-2֮��
		int j = rand() % col;	//0-2֮��



		if (board[i][j] == ' '){
			board[i][j] = WHITE_PIECE;
			break;
		}
	}
	printf("Computer ... Done\n");
	Sleep(1000);
}

void game(int choose){
	int count = 1;	//�õ��Ե�һ��ռ��4��������һ��,�������ѵ��Թ��޲���
	char board[ROW][COL];
	InitBoard(board,ROW,COL);	//��ʼ������

	char result = 'N';	//�ж��Ƿ�����ʤ��
	srand((unsigned long)time(NULL));	//���������

	while (1){
		showBoard(board, ROW, COL);	//����ҿ������
		//����һ��
		int type=playerMove(board, ROW, COL);	
		if (1 == type){
			printf("������������������������룡\n");
			continue;
		}
		else if(2==type){
			printf("������������Ѿ���ռ���ˣ����������룡\n");
			continue;
		}
		else{
			printf("Player ... Done!\n");
		}

		result = JudgeResult(board, ROW, COL);//�ж����
		if (result != 'N'){
			break;
		}

		//�������ѡ����Ѷȣ����Էֱ��߳�һ��
		if (choose == 1){
			//����������һ��
			ComputerMove(board, ROW, COL);
		}
		else if (choose == 2){
			//�м�������һ��
			middleComputerMove(board, ROW, COL);
		}
		else if (choose == 3){
			//�߼�������һ��
			if (count == 1){
				//�߼����Ե�һ��Ҫռ���ĸ�������һ��
				if (board[0][0] == ' '){
					board[0][0] = WHITE_PIECE;
					count++;
				}
				else if (board[0][2] == ' '){
					board[0][2] = WHITE_PIECE;
					count++;
				}
				else if (board[2][0] == ' '){
					board[2][0] = WHITE_PIECE;
					count++;
				}
				else{
					board[2][2] = WHITE_PIECE;
					count++;
				}
			}
			else{
				seniorComputerMove(board, ROW, COL);
			}
		}
		else{
			printf("buf");	//����bug
		}

		result = JudgeResult(board, ROW, COL);//�ж����
		if (result != 'N'){
			break;
		}
	}

	showBoard(board, ROW, COL);	//����ҿ������
	//Ӯ��or����orƽ��
	switch (result){
	case 'E':
		printf("��ϲ�㣬��͵��Դ���һ��ƽ�֣�\n");
		break;
	case BLACK_PIECE:
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
		break;
	case WHITE_PIECE:
		printf("You Lost������Ӯ�ˣ�\n");
		break;
	default:
		printf("����bug\n");
		//bug!
		break;
	}
	//printf("%c\n", result);
}