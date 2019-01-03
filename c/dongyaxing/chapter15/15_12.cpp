class Figure
{
public:
	Figure(double, double);
protected:
	double xSize, ySize;	//图元的尺寸
};

calss Figure_2D : public Figure
{
public:
	Figure_2D(double, double);
	virtual double area() = 0;		//求面积操作：纯虚函数
	virtual double porimeter() = 0;		//求周长操作：纯虚函数
};

class Figure_3D : public Figure
{
public:
	Figure_3D(double, double, double);
	virtual double Cubage() = 0;	//求体积操作：纯虚函数
protected:
	double zSize;	//立体图元的z轴尺寸
};


class Rectangle : public Figure_2D
{
public:
	Rectangle (double, double);
	virtual double area();
	virtual double perimeter();
};

class Circle : public Figure_2D
{
public:
	Circle (double, double = 0);
	virtual double area();
	virtual double perimeter();
};

class Sphere : public Figure_3D
{
public:
	Sphere(double, double, double);
	virtual double cubage();
};

class Cone : public Figure_3D
{
public:
	Cone(double, double, double);
	virtual double cubage();	//冲定义求体积操作
};
