

#include "Render.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

class draw
{
public:
	//Начало с конца (в противном случае фиугра рисуется по часовой, а не против)
	/*
	double dot_1[3] = { 0, 1, height };
	double dot_2[3] = { 5, 4, height };
	double dot_3[3] = { 5, 0, height };
	double dot_4[3] = { 1, -1, height };
	double dot_5[3] = { 1, -6, height };
	double dot_6[3] = { -1, -2, height };
	double dot_7[3] = { -7, -2, height };
	double dot_8[3] = { -6, 5, height };
	double dot_9[3] = { 0, 1, height };
	*/

	void draw_the_thing(double height)
	{
		glBegin(GL_POLYGON);

		glVertex3d(0, 1, height);
		glVertex3d(-6, 5, height);
		glVertex3d(-7, -2, height);
		glVertex3d(-1, -2, height);
		glVertex3d(1, -6, height);
		glVertex3d(1, -1, height);
		glVertex3d(5, 0, height);
		glVertex3d(5, 4, height);
		glVertex3d(0, 1, height);

		glEnd();
	}

	void connect_sides(double height_bottom, double height_upper)
	{
		glBegin(GL_QUADS);

		glVertex3d(0, 1, height_bottom);
		glVertex3d(-6, 5, height_bottom);
		glVertex3d(-6, 5, height_upper);
		glVertex3d(0, 1, height_upper);

		//впуклая часть
		glColor3d(1, 0, 1);
		glVertex3d(-6, 5, height_bottom);
		glVertex3d(-7, -2, height_bottom);
		glVertex3d(-7, -2, height_upper);
		glVertex3d(-6, 5, height_upper);

		glColor3d(0, 0, 0);
		glVertex3d(-7, -2, height_bottom);
		glVertex3d(-1, -2, height_bottom);
		glVertex3d(-1, -2, height_upper);
		glVertex3d(-7, -2, height_upper);

		glVertex3d(-1, -2, height_bottom);
		glVertex3d(1, -6, height_bottom);
		glVertex3d(1, -6, height_upper);
		glVertex3d(-1, -2, height_upper);

		glVertex3d(1, -6, height_bottom);
		glVertex3d(1, -1, height_bottom);
		glVertex3d(1, -1, height_upper);
		glVertex3d(1, -6, height_upper);


		glVertex3d(1, -1, height_bottom);
		glVertex3d(5, 0, height_bottom);
		glVertex3d(5, 0, height_upper);
		glVertex3d(1, -1, height_upper);

		//выпуклая часть
		glColor3d(0, 1, 0);

		glVertex3d(5, 0, height_bottom);
		glVertex3d(5, 4, height_bottom);
		glVertex3d(5, 4, height_upper);
		glVertex3d(5, 0, height_upper);

		//меньший кусок к которому будет проходить выпуклость
		glVertex3d(5*1.25, 1, (height_upper - height_bottom)/2 - (height_upper - height_bottom)/4);
		glVertex3d(5*1.25, 3, (height_upper - height_bottom)/2 - (height_upper - height_bottom) / 4);
		glVertex3d(5*1.25, 3, (height_upper - height_bottom)/2 + (height_upper - height_bottom) / 4);
		glVertex3d(5*1.25, 1, (height_upper - height_bottom)/2 + (height_upper - height_bottom) / 4);

		//соединения выпуклой части с основной
		//левая
		glVertex3d(5, 0, height_bottom);
		glVertex3d(5 * 1.25, 3, (height_upper - height_bottom) / 2 - (height_upper - height_bottom) / 4);
		glVertex3d(5 * 1.25, 1, (height_upper - height_bottom) / 2 - (height_upper - height_bottom) / 4);
		glVertex3d(5, 4, height_bottom);

		//верхняя
		glVertex3d(5, 0, height_upper);
		glVertex3d(5, 4, height_upper);
		glVertex3d(5 * 1.25, 3, (height_upper - height_bottom) / 2 + (height_upper - height_bottom) / 4);
		glVertex3d(5 * 1.25, 1, (height_upper - height_bottom) / 2 + (height_upper - height_bottom) / 4);

		//правая
		glVertex3d(5, 4, height_upper);
		glVertex3d(5, 4, height_bottom);
		glVertex3d(5 * 1.25, 3, (height_upper - height_bottom) / 2 - (height_upper - height_bottom) / 4);
		glVertex3d(5 * 1.25, 3, (height_upper - height_bottom) / 2 + (height_upper - height_bottom) / 4);


		//нижняя
		glVertex3d(5, 0, height_bottom);
		glVertex3d(5 * 1.25, 1, (height_upper - height_bottom) / 2 - (height_upper - height_bottom) / 4);
		glVertex3d(5 * 1.25, 3, (height_upper - height_bottom) / 2 - (height_upper - height_bottom) / 4);
		glVertex3d(5, 4, height_bottom);


		glColor3d(0, 0, 0);
		glVertex3d(5, 4, height_bottom);
		glVertex3d(0, 1, height_bottom);
		glVertex3d(0, 1, height_upper);
		glVertex3d(5, 4, height_upper);

		glEnd();

		
	}

	void draw_in3d(double height_bottom, double height_upper)
	{
		draw_the_thing(height_bottom);
		draw_the_thing(height_upper);
		connect_sides(height_bottom, height_upper);
	}
};

void Render(double delta_time)
{    
	draw thing;
	thing.draw_in3d(0, 1);


}   

