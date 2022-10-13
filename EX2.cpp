#include <iostream>
#include <string>

class Figure {
public:
	double aSide = 0.0; //Общая сторона для всех фигур
	double centerx = 0.0; //х координата центра
	double centery = 0.0; //у координата центра
	double aBorder = 0.0; //длина верхней и нижней границы
	double bBorder = 0.0; //длина правой и левой границы
	double xbpa = 0.0; //х координата точки А границы
	double xbpb = 0.0; //х координата точки В границы
	double xbpc = 0.0; //х координата точки С границы
	double xbpd = 0.0; //х координата точки D границы
	double ybpa = 0.0; //у координата А
	double ybpb = 0.0; //у координата В
	double ybpc = 0.0; //у координата C
	double ybpd = 0.0; //у координата D
	std::string color = "none"; //цвет фигуры
	std::string name = "none"; //название фигуры
};

class Square: public Figure {
public:

	double sqr() { //площадь фигуры
		double s = pow(aSide, 2);
		return s;
	}

	void border() { //вывод параметров границы

		std::cout << "Border: " << std::endl;
		std::cout << "B-----------C" << std::endl;
		for (int i = 0; i < 5; ++i) {
			std::cout << "|           |" << std::endl;
		}
		std::cout << "A-----------D" << std::endl;
		std::cout << "Point A: (" << xbpa << ":" << ybpa << ")" << std::endl;
		std::cout << "Point B: (" << xbpb << ":" << ybpb << ")" << std::endl;
		std::cout << "Point C: (" << xbpc << ":" << ybpc << ")" << std::endl;
		std::cout << "Point D: (" << xbpd << ":" << ybpd << ")" << std::endl;
		std::cout << "AB length: " << aBorder << std::endl;
		std::cout << "BC length: " << aBorder << std::endl;
		std::cout << "CD length: " << aBorder << std::endl;
		std::cout << "DA length: " << aBorder << std::endl;
	}

	void display() { //вывод всех параметров фигуры
		std::cout << "Figure: " << name << std::endl;
		std::cout << "SQUARE" << std::endl;
		std::cout << "Color: " << color << std::endl;
		std::cout << "Center: (" << centerx << ":" << centery << ")" << std::endl;
		std::cout << "a side length: " << aSide << std::endl;
		std::cout << "Square: " << sqr() << std::endl;
		border();
	}


	Square(double inaSide, double inCenterx, double inCentery, std::string inName, std::string inColor) {
		aSide = inaSide; //сторона квадрата
		centerx = inCenterx;
		centery = inCentery;
		name = inName;
		color = inColor;
		aBorder = aSide;
		bBorder = aBorder;
		xbpa = centerx - aBorder / 2;
		xbpb = xbpa;
		xbpc = centerx + aBorder / 2;
		xbpd = xbpc;
		ybpa = centery - bBorder / 2;
		ybpd = ybpa;
		ybpb = centery + bBorder / 2;
		ybpc = ybpb;
	}
};

class Triangle: public Square {
public:
	double bSide = 0.0; //высота треугольника (для определения высоты границы)
	double sqr() {
		double s = pow(aSide, 2) * std::sqrt(3) / 4;
		return s;
	}

	void border() {

		std::cout << "Border: " << std::endl;
		std::cout << "B-----------C" << std::endl;
		for (int i = 0; i < 5; ++i) {
			std::cout << "|           |" << std::endl;
		}
		std::cout << "A-----------D" << std::endl;
		std::cout << "Point A: (" << xbpa << ":" << ybpa << ")" << std::endl;
		std::cout << "Point B: (" << xbpb << ":" << ybpb << ")" << std::endl;
		std::cout << "Point C: (" << xbpc << ":" << ybpc << ")" << std::endl;
		std::cout << "Point D: (" << xbpd << ":" << ybpd << ")" << std::endl;
		std::cout << "AB length: " << bBorder << std::endl;
		std::cout << "BC length: " << aBorder << std::endl;
		std::cout << "CD length: " << bBorder << std::endl;
		std::cout << "DA length: " << aBorder << std::endl;
	}

	void display() {
		std::cout << "Figure: " << name << std::endl;
		std::cout << "Color: " << color << std::endl;
		std::cout << "Center: (" << centerx << ":" << centery << ")" << std::endl;
		std::cout << "a side length: " << aSide << std::endl;
		std::cout << "Square: " << sqr() << std::endl;
		border();
	}
	
	Triangle(double inaSide, double inCenterx, double inCentery, std::string inName, std::string inColor, double inbSide): Square(inaSide, inCenterx, inCentery, inName, inColor) {
		bSide = inbSide;
		bBorder = bSide;
	}
};

class Circle: public Square {
public:
	double sqr() {
		double s = atan(1) * 4 * aSide;
		return s;
	}

	void display() {

		std::cout << "Border: " << std::endl;
		std::cout << "B-----------C" << std::endl;
		for (int i = 0; i < 5; ++i) {
			std::cout << "|           |" << std::endl;
		}
		std::cout << "A-----------D" << std::endl;
		std::cout << "Point A: (" << xbpa << ":" << ybpa << ")" << std::endl;
		std::cout << "Point B: (" << xbpb << ":" << ybpb << ")" << std::endl;
		std::cout << "Point C: (" << xbpc << ":" << ybpc << ")" << std::endl;
		std::cout << "Point D: (" << xbpd << ":" << ybpd << ")" << std::endl;
		std::cout << "AB length: " << bBorder << std::endl;
		std::cout << "BC length: " << aBorder << std::endl;
		std::cout << "CD length: " << bBorder << std::endl;
		std::cout << "DA length: " << aBorder << std::endl;
	}

	void display() {
		std::cout << "Figure: " << name << std::endl;
		std::cout << "Color: " << color << std::endl;
		std::cout << "Center: (" << centerx << ":" << centery << ")" << std::endl;
		std::cout << "Radius: " << aSide << std::endl;
		std::cout << "Square: " << sqr() << std::endl;
		border();
	}

	Circle(double inaSide, double inCenterx, double inCentery, std::string inName, std::string inColor) :Square(inaSide, inCenterx, inCentery, inName, inColor) {

	}
};

class Rectangle : public Triangle {
public:
	double sqr() {
		double s = aSide * bSide;
		return s;
	}

	void border() {

		std::cout << "Border: " << std::endl;
		std::cout << "B-----------C" << std::endl;
		for (int i = 0; i < 5; ++i) {
			std::cout << "|           |" << std::endl;
		}
		std::cout << "A-----------D" << std::endl;
		std::cout << "Point A: (" << xbpa << ":" << ybpa << ")" << std::endl;
		std::cout << "Point B: (" << xbpb << ":" << ybpb << ")" << std::endl;
		std::cout << "Point C: (" << xbpc << ":" << ybpc << ")" << std::endl;
		std::cout << "Point D: (" << xbpd << ":" << ybpd << ")" << std::endl;
		std::cout << "AB length: " << bBorder << std::endl;
		std::cout << "BC length: " << aBorder << std::endl;
		std::cout << "CD length: " << bBorder << std::endl;
		std::cout << "DA length: " << aBorder << std::endl;
	}

	void display() {
		std::cout << "Figure: " << name << std::endl;
		std::cout << "Color: " << color << std::endl;
		std::cout << "Center: (" << centerx << ":" << centery << ")" << std::endl;
		std::cout << "a side length: " << aSide << std::endl;
		std::cout << "b side length: " << bSide << std::endl;
		std::cout << "Square: " << sqr() << std::endl;
		border();
	}

	Rectangle(double inaSide, double inCenterx, double inCentery, std::string inName, std::string inColor, double inbSide) : Triangle(inaSide, inCenterx, inCentery, inName, inColor, inbSide) {
		bSide = inbSide;
		bBorder = bSide;
	}
};

int main() {
	//Чтобы не тратить время на ввод данных все данные уже указаны.
	std::string command = "square";
	//std::cout << "Choose figure: ";
	//std::cin >> command;
	if (command == "square") {
		double inaSide = 10.0;
		double inCenterx = 0.0;
		double inCentery = 0.0;
		std::string inName = "Square";
		std::string inColor = "Green";
		/*std::cout << "Enter a side length: ";
		std::cin >> inaSide;
		std::cout << "Enter center coordinates (x:y): ";
		std::cin >> inCenterx;
		std::cin >> inCentery;
		inName = "square";
		std::cout << "Enter color: ";
		std::cin >> inColor;*/
		Square* square = new Square(inaSide, inCenterx, inCentery, inName, inColor);
		square->display();
	}
	std::cout << "========================================" << std::endl;
	command = "triangle";
	if (command == "triangle") {
		double inaSide = 5.0;
		double inbSide = std::sqrt(3) * inaSide / 2;
		double inCenterx = 0.0;
		double inCentery = 0.0;
		std::string inName = "Triangle";
		std::string inColor = "Blue";
		/*std::cout << "Enter a side length: ";
		std::cin >> inaSide;
		std::cout << "Enter center coordinates (x:y): ";
		std::cin >> inCenterx;
		std::cin >> inCentery;
		inName = "square";
		std::cout << "Enter color: ";
		std::cin >> inColor;*/
		Triangle* triangle = new Triangle(inaSide, inCenterx, inCentery, inName, inColor, inbSide);
		triangle->display();
	}
	std::cout << "========================================" << std::endl;
	command = "circle";
	if (command == "circle") {
		double inaSide = 15.0; //radius
		double inCenterx = 0.0;
		double inCentery = 0.0;
		std::string inName = "Circle";
		std::string inColor = "Red";
		/*std::cout << "Enter a side length: ";
		std::cin >> inaSide;
		std::cout << "Enter center coordinates (x:y): ";
		std::cin >> inCenterx;
		std::cin >> inCentery;
		inName = "square";
		std::cout << "Enter color: ";
		std::cin >> inColor;*/
		Circle* circle = new Circle(inaSide, inCenterx, inCentery, inName, inColor);
		circle->display();
	}
	std::cout << "========================================" << std::endl;
	command = "rectangle";
	if (command == "rectangle") {
		double inaSide = 6.0;
		double inbSide = 25.0;
		double inCenterx = 0.0;
		double inCentery = 0.0;
		std::string inName = "Rectangle";
		std::string inColor = "Pink";
		/*std::cout << "Enter a side length: ";
		std::cin >> inaSide;
		std::cout << "Enter center coordinates (x:y): ";
		std::cin >> inCenterx;
		std::cin >> inCentery;
		inName = "square";
		std::cout << "Enter color: ";
		std::cin >> inColor;*/
		Rectangle* rectangle = new Rectangle(inaSide, inCenterx, inCentery, inName, inColor, inbSide);
		rectangle->display();
	}
	return 0;
}


