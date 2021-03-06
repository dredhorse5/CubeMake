//#include <SOIL.h>
#include <glut.h>
#include <iostream>

float angle = 0.0f;

void changeSize(int w, int h) {
	// �������������� ������� �� ����
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;
	// ���������� ������� ��������
	glMatrixMode(GL_PROJECTION);
	// �������� �������
	glLoadIdentity();
	// ���������� ��������� ��������
	glViewport(0, 0, w, h);
	// ���������� ���������� �����������
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	// ��������� � ������� ��������
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	///////////////////////////////
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, -0.9, 0.0);
	glEnd();

	glutSwapBuffers();
}

int main(int argc, char* argv[]) {

	// �������������
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("���� 1");

	// ����������� �������� �������
	glutDisplayFunc(renderScene);

	// �������� ���� GLUT
	glutMainLoop();

	return 1;
}