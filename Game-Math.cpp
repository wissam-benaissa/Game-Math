#include <iostream>
#include <cmath>
#include <string>
using namespace std;
enum enQuestionLevel {Easy = 1, Med = 2, Hard = 3, MixLevels = 4};
enum enOperationType {Add = 1, Sub = 2, Mul = 3, Div = 4, MixOperations = 5};
enum enAnswerType {Right = 1, Fail = 2};

struct stQuizzInfo {
	short QuestionNumber = 0;
	short Number1 = 0;
	short Number2 = 0;
	enQuestionLevel QuestionLevelChoice;
	enOperationType OperationTypeChoice;
	enAnswerType AnswerType;
	string Answer = ""; 
};
struct stQuizzResult {
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
};

short HowManyQuestions() {
	short Questions = 0;

	do {
		cout << "How Many Questions You Wnat To Answer ? \n";
		cin >> Questions;
	} while (Questions > 10 || Questions < 0);

	return Questions;
}
short RandomNumber(int From, int To) {
	short RandNum = 0;

	RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}
char RandomOperationCharacter(short From, short To) {
	char RandChar;

	RandChar = rand() % (To - From + 1) + From;

	return RandChar;
}
char FixeROC(char RandomOC) {
	switch (RandomOC) {
	case 44:
		RandomOC = 45;
		break;
	case 46:
		RandomOC = 47;
		break;
	}

	return RandomOC;
}

enQuestionLevel ReadPlayerQuestionLevelChoice() {
	short PlayerQuestionLevelChoice = 0;
	do {

		cout << "Entre Question Level: [1] Easy, [2] Med, [3] Hard, [4] MixLevels \n";
		cin >> PlayerQuestionLevelChoice;

	} while (PlayerQuestionLevelChoice < 1 || PlayerQuestionLevelChoice > 4);
	

	return (enQuestionLevel)PlayerQuestionLevelChoice;  
} 
enOperationType ReadPlayerOperationTypeChoice() {
	short PlayerOperationTypeChoice = 0;
	do {

		cout << "Entre Operation Type: [1] Add, [2] Sub, [3] Mul, [4] Div, [5] MixOperations \n";
		cin >> PlayerOperationTypeChoice;

	} while (PlayerOperationTypeChoice < 1 || PlayerOperationTypeChoice > 5);

	

	return (enOperationType)PlayerOperationTypeChoice; 
}
string PrintAnswerType(enAnswerType AnswerType) {
	string AnswerName = "";
	if (AnswerType == enAnswerType::Right) {
		return AnswerName = "Right Answer :)";
	}
	else
		return AnswerName = "Fail Answer :(";
}
string PrintFinalResult(short RightAnswers, short WrongAnswers) {
	string FinalResult = "";
	if (RightAnswers > WrongAnswers) {
		system("Color 2F");
		return FinalResult = "Pass :)";
	}
	else if (RightAnswers < WrongAnswers) {
		system("Color 4F");
		return FinalResult = "Fail :(";
	}
	else
		return FinalResult = "Pass :)";

}
string PrintQuestionLevelChoice(enQuestionLevel QuestionLevel) {
	string PrintQuestionLevel = "";

	switch (QuestionLevel) {
	case enQuestionLevel::Easy:
		return PrintQuestionLevel = "Easy";
	case enQuestionLevel::Med:
		return PrintQuestionLevel = "Medium";
	case enQuestionLevel::Hard:
		return PrintQuestionLevel = "Hard";
	}

	return PrintQuestionLevel = "Mix Levels";
}
string PrintOperationTypeChoice(enOperationType OperationType) {
	string PrintOperationType = "";

	switch (OperationType) {
	case enOperationType::Add:
		return PrintOperationType = "Add";
	case enOperationType::Sub:
		return PrintOperationType = "Subtract";
	case enOperationType::Mul:
		return PrintOperationType = "Multiply";
	case enOperationType::Div:
		return PrintOperationType = "Divide";
	}

	return PrintOperationType = "Mix Operations";
}

void SetRightAndFailScreenColor(enAnswerType Answer) {
	switch (Answer) {
	case enAnswerType::Right:
		system("Color 2F");
		break;
	case enAnswerType::Fail:
		system("Color 4F");
		cout << "\a";
		break;
	}
}

void AddOperations(stQuizzInfo QuizzInfo, stQuizzResult &QuizzResult) {
	int PlayerAnswer = 0;
	int TheRightAnswer = 0;

	cout << QuizzInfo.Number1 << "\n + \n" << QuizzInfo.Number2;
	cout << "\n-----------\n";
	cin >> PlayerAnswer;
	if (PlayerAnswer == (QuizzInfo.Number1 + QuizzInfo.Number2)) { 
		QuizzInfo.AnswerType = enAnswerType::Right;
		QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType); 
		cout << QuizzInfo.Answer << endl;
		SetRightAndFailScreenColor(QuizzInfo.AnswerType);
		QuizzResult.NumberOfRightAnswers++; 
	}
	else {
		QuizzInfo.AnswerType = enAnswerType::Fail;
		QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType); 
		cout << QuizzInfo.Answer << endl;
		SetRightAndFailScreenColor(QuizzInfo.AnswerType);
		TheRightAnswer = QuizzInfo.Number1 + QuizzInfo.Number2;
		cout << "The Right Answer is: " << TheRightAnswer << endl;
		QuizzResult.NumberOfWrongAnswers++; 
	}

}
void SubOperation(stQuizzInfo QuizzInfo, stQuizzResult& QuizzResult) {
	int PlayerAnswer = 0;
	int TheRightAnswer = 0;

	cout << QuizzInfo.Number1 << "\n - \n" << QuizzInfo.Number2;
	cout << "\n-----------\n";
	cin >> PlayerAnswer;
	if (PlayerAnswer == (QuizzInfo.Number1 - QuizzInfo.Number2)) {
		QuizzInfo.AnswerType = enAnswerType::Right;
		QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType);
		cout << QuizzInfo.Answer << endl;
		SetRightAndFailScreenColor(QuizzInfo.AnswerType);
		QuizzResult.NumberOfRightAnswers++;
	}
	else {
		QuizzInfo.AnswerType = enAnswerType::Fail;
		QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType);
		cout << QuizzInfo.Answer << endl;
		SetRightAndFailScreenColor(QuizzInfo.AnswerType);
		TheRightAnswer = QuizzInfo.Number1 - QuizzInfo.Number2;
		cout << "The Right Answer is: " << TheRightAnswer << endl;
		QuizzResult.NumberOfWrongAnswers++;
	}

}
void MulOperation(stQuizzInfo QuizzInfo, stQuizzResult& QuizzResult) {
	int PlayerAnswer = 0;
	int TheRightAnswer = 0;

	cout << QuizzInfo.Number1 << "\n * \n" << QuizzInfo.Number2;
	cout << "\n-----------\n";
	cin >> PlayerAnswer;
	if (PlayerAnswer == (QuizzInfo.Number1 * QuizzInfo.Number2)) {
		QuizzInfo.AnswerType = enAnswerType::Right;
		QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType);
		cout << QuizzInfo.Answer << endl;
		SetRightAndFailScreenColor(QuizzInfo.AnswerType);
		QuizzResult.NumberOfRightAnswers++;
	}
	else {
		QuizzInfo.AnswerType = enAnswerType::Fail;
		QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType);
		cout << QuizzInfo.Answer << endl;
		SetRightAndFailScreenColor(QuizzInfo.AnswerType);
		TheRightAnswer = QuizzInfo.Number1 * QuizzInfo.Number2;
		cout << "The Right Answer is: " << TheRightAnswer << endl;
		QuizzResult.NumberOfWrongAnswers++;

	}

}
void DivOperation(stQuizzInfo QuizzInfo, stQuizzResult& QuizzResult) {
	int PlayerAnswer = 0;
	int TheRightAnswer = 0;

	cout << QuizzInfo.Number1 << "\n / \n" << QuizzInfo.Number2;
	cout << "\n-----------\n";
	cin >> PlayerAnswer;
	if (PlayerAnswer == (QuizzInfo.Number1 / QuizzInfo.Number2)) {
		QuizzInfo.AnswerType = enAnswerType::Right;
		QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType);
		cout << QuizzInfo.Answer << endl;
		SetRightAndFailScreenColor(QuizzInfo.AnswerType);
		QuizzResult.NumberOfRightAnswers++;
	}
	else {
		QuizzInfo.AnswerType = enAnswerType::Fail;
		QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType);
		cout << QuizzInfo.Answer << endl;
		SetRightAndFailScreenColor(QuizzInfo.AnswerType);
		TheRightAnswer = QuizzInfo.Number1 / QuizzInfo.Number2;
		cout << "The Right Answer is: " << TheRightAnswer << endl;
		QuizzResult.NumberOfWrongAnswers++;
	}

}
void MixOperationss(stQuizzInfo QuizzInfo, stQuizzResult& QuizzResult, char RandomOperation) {
	int PlayerAnswer = 0;
	int TheRightAnswer = 0;

	cout << QuizzInfo.Number1 << "\n";
	cout << RandomOperation << "\n" << QuizzInfo.Number2;
	cout << "\n-----------\n";
	cin >> PlayerAnswer;
	switch (RandomOperation) {
	case '+':
		if (PlayerAnswer == QuizzInfo.Number1 + QuizzInfo.Number2) { 
			QuizzInfo.AnswerType = enAnswerType::Right;  
			QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType); 
			cout << QuizzInfo.Answer << endl;  
			SetRightAndFailScreenColor(QuizzInfo.AnswerType);
			QuizzResult.NumberOfRightAnswers++; 

		}
		else {
			QuizzInfo.AnswerType = enAnswerType::Fail; 
			QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType); 
			cout << QuizzInfo.Answer << endl; 
			SetRightAndFailScreenColor(QuizzInfo.AnswerType);
			TheRightAnswer = QuizzInfo.Number1 + QuizzInfo.Number2; 
			cout << "The Right Answer is: " << TheRightAnswer << endl; 
			QuizzResult.NumberOfWrongAnswers++; 
		};
		break;
	case '-':
		if (PlayerAnswer == QuizzInfo.Number1 - QuizzInfo.Number2) {
			QuizzInfo.AnswerType = enAnswerType::Right;
			QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType);
			cout << QuizzInfo.Answer << endl;
			SetRightAndFailScreenColor(QuizzInfo.AnswerType);
			QuizzResult.NumberOfRightAnswers++;

		}
		else {
			QuizzInfo.AnswerType = enAnswerType::Fail;
			QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType);
			cout << QuizzInfo.Answer << endl;
			SetRightAndFailScreenColor(QuizzInfo.AnswerType); 
			TheRightAnswer = QuizzInfo.Number1 - QuizzInfo.Number2;
			cout << "The Right Answer is: " << TheRightAnswer << endl;
			QuizzResult.NumberOfWrongAnswers++;
		};
		break;
	case '*':
		if (PlayerAnswer == QuizzInfo.Number1 * QuizzInfo.Number2) {
			QuizzInfo.AnswerType = enAnswerType::Right;
			QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType);
			cout << QuizzInfo.Answer << endl;
			SetRightAndFailScreenColor(QuizzInfo.AnswerType);
			QuizzResult.NumberOfRightAnswers++;

		}
		else {
			QuizzInfo.AnswerType = enAnswerType::Fail;
			QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType);
			cout << QuizzInfo.Answer << endl;
			SetRightAndFailScreenColor(QuizzInfo.AnswerType);
			TheRightAnswer = QuizzInfo.Number1 * QuizzInfo.Number2;
			cout << "The Right Answer is: " << TheRightAnswer << endl;
			QuizzResult.NumberOfWrongAnswers++;
		};
		break;
	case '/':
		if (PlayerAnswer == QuizzInfo.Number1 / QuizzInfo.Number2) {
			QuizzInfo.AnswerType = enAnswerType::Right;
			QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType);
			cout << QuizzInfo.Answer << endl;
			SetRightAndFailScreenColor(QuizzInfo.AnswerType);
			QuizzResult.NumberOfRightAnswers++;

		}
		else {
			QuizzInfo.AnswerType = enAnswerType::Fail;
			QuizzInfo.Answer = PrintAnswerType(QuizzInfo.AnswerType);
			cout << QuizzInfo.Answer << endl;
			SetRightAndFailScreenColor(QuizzInfo.AnswerType);
			TheRightAnswer = QuizzInfo.Number1 / QuizzInfo.Number2;
			cout << "The Right Answer is: " << TheRightAnswer << endl;
			QuizzResult.NumberOfWrongAnswers++;
		};
		break;
	}
	
}

void ResetScreenColor() {
	system("cls");
	system("color 0F");
}

stQuizzInfo PlayGame(short HowManyQuestions, stQuizzResult QuizzResult) {
	stQuizzInfo QuizzInfo;

	QuizzInfo.QuestionLevelChoice = ReadPlayerQuestionLevelChoice();
	QuizzInfo.OperationTypeChoice = ReadPlayerOperationTypeChoice();

	for (short Question = 1; Question <= HowManyQuestions; Question++) {
		QuizzInfo.QuestionNumber = Question;
		cout << "Question [" << QuizzInfo.QuestionNumber << "/" << HowManyQuestions << "] \n";
		switch (QuizzInfo.QuestionLevelChoice) {
		case enQuestionLevel::Easy:
			QuizzInfo.Number1 = RandomNumber(1, 10);
			QuizzInfo.Number2 = RandomNumber(1, 10);
			if (QuizzInfo.OperationTypeChoice == enOperationType::Add) {
				AddOperations(QuizzInfo, QuizzResult);
			}
			else if (QuizzInfo.OperationTypeChoice == enOperationType::Sub) {
				SubOperation(QuizzInfo, QuizzResult);
			}
			else if (QuizzInfo.OperationTypeChoice == enOperationType::Mul) {
				MulOperation(QuizzInfo, QuizzResult);
			}
			else if (QuizzInfo.OperationTypeChoice == enOperationType::Div) {
				DivOperation(QuizzInfo, QuizzResult);
			}
			else
				MixOperationss(QuizzInfo, QuizzResult, FixeROC(RandomOperationCharacter(42, 47))); 
			break;
		case enQuestionLevel::Med:
			QuizzInfo.Number1 = RandomNumber(10, 100);
			QuizzInfo.Number2 = RandomNumber(10, 100);
			if (QuizzInfo.OperationTypeChoice == enOperationType::Add) {
				AddOperations(QuizzInfo, QuizzResult);
			}
			else if (QuizzInfo.OperationTypeChoice == enOperationType::Sub) {
				SubOperation(QuizzInfo, QuizzResult);
			}
			else if (QuizzInfo.OperationTypeChoice == enOperationType::Mul) {
				MulOperation(QuizzInfo, QuizzResult);
			}
			else if (QuizzInfo.OperationTypeChoice == enOperationType::Div) {
				DivOperation(QuizzInfo, QuizzResult);
			}
			else
				MixOperationss(QuizzInfo, QuizzResult, FixeROC(RandomOperationCharacter(42, 47))); 
			break;
		case enQuestionLevel::Hard:
			QuizzInfo.Number1 = RandomNumber(100, 1000);
			QuizzInfo.Number2 = RandomNumber(100, 1000);
			if (QuizzInfo.OperationTypeChoice == enOperationType::Add) {
				AddOperations(QuizzInfo, QuizzResult);
			}
			else if (QuizzInfo.OperationTypeChoice == enOperationType::Sub) {
				SubOperation(QuizzInfo, QuizzResult);
			}
			else if (QuizzInfo.OperationTypeChoice == enOperationType::Mul) {
				MulOperation(QuizzInfo, QuizzResult);
			}
			else if (QuizzInfo.OperationTypeChoice == enOperationType::Div) {
				DivOperation(QuizzInfo, QuizzResult);
			}
			else
				MixOperationss(QuizzInfo, QuizzResult, FixeROC(RandomOperationCharacter(42, 47))); 
			break;
		case enQuestionLevel::MixLevels:
			QuizzInfo.Number1 = RandomNumber(1, 1000);
			QuizzInfo.Number2 = RandomNumber(1, 1000);
			if (QuizzInfo.OperationTypeChoice == enOperationType::Add) { 
				AddOperations(QuizzInfo, QuizzResult); 
			}
			else if (QuizzInfo.OperationTypeChoice == enOperationType::Sub) { 
				SubOperation(QuizzInfo, QuizzResult);
			}
			else if (QuizzInfo.OperationTypeChoice == enOperationType::Mul) { 
				MulOperation(QuizzInfo, QuizzResult);
			}
			else if (QuizzInfo.OperationTypeChoice == enOperationType::Div) { 
				DivOperation(QuizzInfo, QuizzResult);
			}
			else
				MixOperationss(QuizzInfo, QuizzResult, FixeROC(RandomOperationCharacter(42, 47)));
			break;
		}
	}
	cout << endl;

	cout << "\n---------------------------------\n";
	cout << "  Final Results is: " << PrintFinalResult(QuizzResult.NumberOfRightAnswers, QuizzResult.NumberOfWrongAnswers);
	cout << "\n---------------------------------\n";
	cout << "Number Of Questions: " << HowManyQuestions << "\n";
	cout << "Questions Level: " << PrintQuestionLevelChoice(QuizzInfo.QuestionLevelChoice) << "\n";
	cout << "Operations Type: " << PrintOperationTypeChoice(QuizzInfo.OperationTypeChoice) << "\n";
	cout << "Number Of Rights Answers: " << QuizzResult.NumberOfRightAnswers << "\n";
	cout << "Number Of Wrong Answers: " << QuizzResult.NumberOfWrongAnswers << "\n";
	cout << "---------------------------------" << endl; 


	return QuizzInfo;
}

void StartGame() {
	stQuizzResult QuizzResult;
	short Questions = HowManyQuestions();
	stQuizzInfo QuizzInfo = PlayGame(Questions, QuizzResult);
}

int main()
{
	srand((unsigned)time(NULL));

	char PlayAgain = 'Y';

	do {

		ResetScreenColor();
		StartGame();   
		cout << endl; 

		cout << "\t\tDo you want to play again ? [Y/y]: Yes  [N/n]: No \n";
		cin >> PlayAgain;

	} while (PlayAgain == 'y' || PlayAgain == 'Y');
	
	
	  
	return 0;
} 
