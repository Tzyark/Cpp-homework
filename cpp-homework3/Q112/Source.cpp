#include <iostream>

using namespace std;

class Operation {
private:
	double NumberA;
	double NumberB;
public:
	virtual double GetResult() {
		return 0;
	};
	double getA() {
		return NumberA;
	}
	void setA(double _NumberA) {
		NumberA = _NumberA;
	}
	double getB() {
		return NumberB;
	}
	void setB(double _NumberB) {
		NumberB = _NumberB;
	}
};

class OperationAdd : public Operation {
public:
	double GetResult() override {
		return getA() + getB();
	}
};

class OperationSub : public Operation {
public:
	double GetResult() override {
		return getA() - getB();
	}
};

class OperationMul : public Operation {
public:
	double GetResult() override {
		return getA() * getB();
	}
};

class OperationDiv : public Operation {
public:
	double GetResult() override {
		return getB() == 0 ? -1 : getA() / getB();
	}
};

class OperationFactory {
public:
	Operation *CreateOperation(const char &oper) {
		Operation *ret;
		switch (oper) {
		case '+':
			ret = new OperationAdd();
			break;
		case '-':
			ret = new OperationSub();
			break;
		case '*':
			ret = new OperationMul();
			break;
		case '/':
			ret = new OperationDiv();
			break;
		default:
			ret = NULL;
			break;
		}
		return ret;
	}
};

int main(int argc, char *argv[]) {
	char oper;
	cin >> oper;
	Operation *operation = new Operation;
	OperationFactory operationFactory;
	operation = operationFactory.CreateOperation(oper);
	double a;	
	cin >> a;
	operation->setA(a);
	double b;
	cin >> b;
	operation->setB(b);
	cout << operation->GetResult() << endl;
	return 0;
}