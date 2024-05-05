//封装函数显示通讯录界面
#include <iostream>
using namespace std;
#define MAX 1000//定义最大联系人数
//设计联系人结构体
struct Person {
	//姓名
	string name;
	//性别 1为男 2为女
	int sex;
	//年龄
	int age;
	//电话
	string phoneNumber;
	//住址
	string address;
};
//设计通讯录结构体
struct AddressBook {
	//联系人数组
	Person person[MAX];
	//记录当前已有联系人数
	int size=0;
};
//添加联系人函数
void addPerson(AddressBook* addressbook) {
	//判断通讯录是否已满，满的话则提示
	if (addressbook->size >= MAX) {
		cout << "通讯录已满" << endl;
	}
	//如果没满,输入联系人信息
	else {
		//添加具体联系人
		Person person;
		//姓名
		cout << "输入姓名" << endl;
		cin >> addressbook->person[addressbook->size].name;
		//性别
		cout << "请输入性别(1为男，2为女)" << endl;
		cin >> addressbook->person[addressbook->size].sex;
		//年龄
		cout << "请输入年龄" << endl;
		cin >> addressbook->person[addressbook->size].age;
		//电话
		cout << "请输入电话" << endl;
		cin >> addressbook->person[addressbook->size].phoneNumber;
		//检查电话位数是否正确
		while(addressbook->person[addressbook->size].phoneNumber.length() != 11) {
			cout << "电话号码位数不正确" << endl;
			cout<<"请重新输入电话号码"<<endl;
			cin >> addressbook->person[addressbook->size].phoneNumber;
		}
		//住址
		cout << "请输入住址" << endl;
		cin >> addressbook->person[addressbook->size].address;
		//将当前已有联系人数加1
		addressbook->size++;
		//请按任意键继续
		system("pause");
		//清屏
		system("cls");
	}
}
//显示联系人函数
void showPerson(AddressBook* addressbook) {
	//判断通讯录是否为空，为空的话则提示
	if (addressbook->size == 0) {
		cout << "通讯录为空" << endl;
	}
	//否则，显示所有联系人信息
	else {
		//显示所有联系人信息
		for (int i = 0; i < addressbook->size; i++) {
			cout << "姓名：" << addressbook->person[i].name << "\t";
			cout << "性别：" << (addressbook->person[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << addressbook->person[i].age << "\t";
			cout << "电话：" << addressbook->person[i].phoneNumber << "\t";
			cout << "住址：" << addressbook->person[i].address << endl;
			cout << "-" << endl;
		}
		//请按任意键继续
		system("pause");
		//清屏
		system("cls");
	}
}
//检查联系人是否存在，如果存在返回联系人的具体位置，不存在返回-1
//参数1：通讯录结构体变量
//参数2：联系人姓名
int ifPersonExist(AddressBook* addressbook, string name) {
	for (int i = 0;i < addressbook->size;i++) {
		if (addressbook->person[i].name == name) {
			return i + 1;
		}
	}
	return -1;
}
//删除联系人函数
void deletePerson(AddressBook* addressbook, string name) {
	//1:判断通讯录是否为空
	if (addressbook->size == 0) {
		cout << "通讯录为空" << endl;
	}
	else {
		//2:判断联系人是否存在
		int index = ifPersonExist(addressbook, name);
			//如果index不为-1.代表联系人存在，则进行删除操作
			if (index != -1) {
				//解释:为什么是i等于index-1
				//因为在ifPersonExist函数中，返回的是联系人的索引值，所以要减1才是数组的索引值
				//第二:为什么是i<addressbook->size-1
				//因为在删除了一个联系人之后，数组中的联系人已经少了一个了
				//所有为了避免数组越界访问，导致内存泄露，要小于address->size-1
				for (int i = index - 1;i < addressbook->size - 1;i++) {
					//删除联系人，直接将联系人后面的联系人前移一位
					addressbook->person[i] = addressbook->person[i + 1];
				}
				//联系人-1
				addressbook->size--;
			}
			//如果index为-1.代表联系人不存在，则提示
			else {
				cout << "联系人不存在" << endl;
			}
	}
	cout<<"请按任意键继续"<<endl;
	system("pause");
	system("cls");
}
//查找联系人函数
// 用户输入联系人的姓名，显示联系人的所有信息
void findPerson(AddressBook* addressbook, string name1) {
	//判断联系人是否存在
	//将index命名为-1，如果联系人存在，则将其索引值赋给index
	//如果联系人不存在，则index仍为-1，打印联系人不存在
	int index = -1;
	for (int i = 0;i < addressbook->size;i++) {
		if (addressbook->person[i].name == name1) {
			index = i;
			break;
		}
	}
		if (index == -1)
			cout << "联系人不存在" << endl;
		else {
			//打印联系人的信息
			cout << "姓名：" << addressbook->person[index].name << "\t";
			cout << "性别：" << (addressbook->person[index].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << addressbook->person[index].age << "\t";
			cout << "电话：" << addressbook->person[index].phoneNumber << "\t";
			cout << "住址：" << addressbook->person[index].address << endl;
		}
}
//修改联系人函数
void modifyPerson(AddressBook* addressbook) {
	cout << "请输入您要修改的联系人姓名" << endl;
	//用户输入
	string name;
	cin >>name;
	//判断联系人是否存在
	int index = ifPersonExist(addressbook, name);
	//index不为-1.代表联系人存在
	if (index != -1) {
		//修改联系人信息
		//姓名
		cout << "请输入新的姓名" << endl;
		cin >> addressbook->person[index - 1].name;
		//性别
		cout << "请输入新的性别(1为男，2为女)" << endl;
		cin >> addressbook->person[index - 1].sex;
		//年龄
		cout << "请输入新的年龄" << endl;
		cin >> addressbook->person[index - 1].age;
		//电话
		cout << "请输入新的电话" << endl;
		cin >> addressbook->person[index - 1].phoneNumber;
		//检查电话位数是否正确
		while (addressbook->person[index - 1].phoneNumber.length() != 11) {
			cout << "电话号码位数不正确" << endl;
			cout << "请重新输入电话号码" << endl;
			cin >> addressbook->person[index - 1].phoneNumber;
		}
		//住址
		cout << "请输入新的住址" << endl;
		cin >> addressbook->person[index - 1].address;
		cout << "联系人信息修改成功" << endl;
	}
	//index为-1.代表联系人不存在
	else {
		cout << "联系人不存在" << endl;

	}
}
//清空联系人函数
// 为了方便，直接将通讯录结构体的size置为0即可
// 这么做主要还是因为再次打开会重置程序
void clearPerson(AddressBook* addressbook) {
	addressbook->size = 0;
}
//菜单界面
void showMenu() {
	cout << "*****1添加联系人*****" << endl;
	cout << "*****2显示联系人*****" << endl;
	cout << "*****3删除联系人*****" << endl;
	cout << "*****4查找联系人*****" << endl;
	cout << "*****5修改联系人*****" << endl;
	cout << "*****6清空联系人*****" << endl;
	cout << "*****0退出通讯录*****" << endl;

}
int main() {
	//创建用户选择的变量
	int select = 1;
	//创建通讯录结构体变量
	AddressBook addressbook;
	//初始化通讯录结构体变量
	addressbook.size = 0;

	while (select!=0) {
		//调用菜单
		showMenu();
		//用户输入
		cin >> select;
		//判断用户选择
		switch (select) {
			//添加联系人
		case 1:
			addPerson(&addressbook);
			break;
			//显示联系人
		case 2:
			showPerson(&addressbook);
			break;
			//删除联系人
		case 3:
		{//表示一个代码块，防止报错,代码块结束符号为“}”
			cout << "请输入删除的联系人姓名" << endl;
			string name;//删除的联系人姓名
			cin >> name;//用户输入
			//判断是否存在
			int index = ifPersonExist(&addressbook, name);
			if (index != -1) {
				//删除联系人
				deletePerson(&addressbook, name);
				cout << "联系人删除成功" << endl;
			}


			else {
				cout << "联系人不存在" << endl;
			}
		}
		break;
		//查找联系人
		case 4:
		{//表示一个代码块，防止报错,代码块结束符号为“}”
			string name1;
			cout << "请输入您要查找的联系人" << endl;
			cin >> name1;
			findPerson(&addressbook, name1);
			//清屏操作
			cout << "请按任意键继续" << endl;
			system("pause");
			system("cls");
		}
			break;
			//修改联系人
		case 5:
			modifyPerson(&addressbook);
			break;
			//清空联系人
		case 6:
			clearPerson(&addressbook);
			cout << "通讯录已清空" << endl;
			break;
			//退出通讯录
		case 0:
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}