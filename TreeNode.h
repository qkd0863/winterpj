#pragma once


struct Matrix
{
	float x, y, width, height;
	Matrix(float _x, float _y, float _width, float _height)
	{
		x = _x, y = _y, width = _width, height = _height;
	}
	Matrix() { x = -1, y = -1, width = -1, height - 1;}
	~Matrix() { }
};

enum DIRECTION
{
	WIDTH,
	HEIGHT
};

class TreeNode
{
private:
	TreeNode* leftNode;
	TreeNode* rightNode;
	TreeNode* parentNode;
	Matrix info;
	Matrix roominfo;
	int direction;
	bool connect;
	bool solo;

public:
	void MakeLeftTree(TreeNode* sub)
	{
		if (this->leftNode != NULL)
			this->leftNode = NULL;
		this->leftNode = sub;
	}
	void MakeRightTree(TreeNode* sub)
	{
		if (this->rightNode != NULL)
			this->rightNode = NULL;
		this->rightNode = sub;
	}
	void MakeConnection();
	void MakeHurdle(Matrix romminfo);
	void SetInfo(Matrix sub) { info = sub; }
	void SetParentNode(TreeNode* sub) { parentNode = sub; }
	void SetDirection(int dir) { direction = dir; }
	void SetRoomInfo(Matrix sub) { roominfo = sub; }
	void SetSolo(bool _solo) { solo = _solo; }
	int GetDirection() { return direction; }
	bool GetConnect() { return connect; }
	bool GetSolo() { return solo; }
	Matrix GetRoomInfo() { return roominfo; }
	Matrix GetInfo() { return info; }
	TreeNode* GetParentNode() { return parentNode; }
	TreeNode* GetLeftNode() { return leftNode; }
	TreeNode* GetRightNode() { return rightNode; }
	TreeNode()
	{
		connect = false;
		leftNode = nullptr;
		rightNode = nullptr;
		parentNode = nullptr;
		solo = false;
	}
};