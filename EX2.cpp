#include <iostream>
#include <string>

class Figure {
public:
	double aSide = 0.0; //Общая сторона для всех фигур
	double centerx = 0.0; //х координата центра
	double centery = 0.0; //у координата центра
	std::string color = "none"; //цвет фигуры
	std::string name = "none"; //название фигуры
};

class Rectangle : public Figure {
public:
	double bSide = 0.0; //Высота прямоугольника
	double sqr() {
		double s = aSide * bSide;
		return s;
	}

	void border() {
		std::cout << "Border: " << std::endl;
		std::cout << "Width: " << aSide << std::endl;
		std::cout << "Height: " << bSide << std::endl;
	}

	void display() {
		std::cout << "Figure: " << name << std::endl;
		std::cout << "Color: " << color << std::endl;
		std::cout << "Center: (" << centerx << ":" << centery << ")" << std::endl;
		std::cout << "A side length: " << aSide << std::endl;
		std::cout << "B side length: " << bSide << std::endl;
		std::cout << "Square: " << sqr() << std::endl;
		border();
	}

	Rectangle(double inaSide, double inCenterx, double inCentery, std::string inName, std::string inColor, double inbSide) {
		centerx = inCenterx;
		centery = inCentery;
		name = inName;
		color = inColor;
		aSide = inaSide;
		bSide = inbSide;
	}
};

class Square : public Figure {
public:

	double sqr() { //площадь фигуры
		double s = pow(aSide, 2);
		return s;
	}

	void border() { //вывод параметров границы
		Rectangle* border = new Rectangle(aSide, centerx, centery, "Border of square", "none", aSide);
		border->border();
		delete border;
	}

	void display() { //вывод всех параметров фигуры
		std::cout << "Figure: " << name << std::endl;
		std::cout << "Color: " << color << std::endl;
		std::cout << "Center: (" << centerx << ":" << centery << ")" << std::endl;
		std::cout << "A side length: " << aSide << std::endl;
		std::cout << "B side length: " << aSide << std::endl;
		std::cout << "Square: " << sqr() << std::endl;
		border();
	}


	Square(double inaSide, double inCenterx, double inCentery, std::string inName, std::string inColor){
		centerx = inCenterx;
		centery = inCentery;
		name = inName;
		color = inColor;
		aSide = inaSide;
	}
};

class Triangle : public Rectangle {
public:
	double sqr() {
		double s = pow(aSide, 2) * std::sqrt(3) / 4;
		return s;
	}

	void border() {
		Rectangle* border = new Rectangle(aSide, centerx, centery, "Border of triangle", "none", bSide);
		border->border();
		delete border;
	}

	void display() {
		std::cout << "Figure: " << name << std::endl;
		std::cout << "Color: " << color << std::endl;
		std::cout << "Center: (" << centerx << ":" << centery << ")" << std::endl;
		std::cout << "A side length: " << aSide << std::endl;
		std::cout << "B side length: " << bSide << std::endl;
		std::cout << "Square: " << sqr() << std::endl;
		border();
	}

	Triangle(double inaSide, double inCenterx, double inCentery, std::string inName, std::string inColor, double inbSide) : Rectangle(inaSide, inCenterx, inCentery, inName, inColor, inbSide) {
		centerx = inCenterx;
		centery = inCentery;
		name = inName;
		color = inColor;
		aSide = inaSide;
		bSide = inbSide;
	}
};

class Circle : public Square {
public:
	double sqr() {
		double s = atan(1) * 4 * aSide;
		return s;
	}

	void border() {
		Rectangle* border = new Rectangle(aSide * 2, centerx, centery, "Border of circle", "none", aSide * 2);
		border->border();
		delete border;
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
		centerx = inCenterx;
		centery = inCentery;
		name = inName;
		color = inColor;
		aSide = inaSide;
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
		delete square;
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
		delete triangle;
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
		delete circle;
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
		delete rectangle;
	}
	return 0;
}


