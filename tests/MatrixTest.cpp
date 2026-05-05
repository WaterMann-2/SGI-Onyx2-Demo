//
// Created by robsc on 5/3/26.
//

#include <graphics/Graphics.h>
#include <math/Matrix.h>

int main(int argc,char* argv[]) {
	SpGL::Matrix<float> FalseMatrixExample(4,2);

	FalseMatrixExample.SetToIdentity();
	std::printf("%s", (FalseMatrixExample.ToString() + '\n').c_str());
	//Will say it's incorrect

	SpGL::Vector3<float> vec3(2.0f, 4.0f, 6.0f);
	SpGL::Matrix4<float> mat4(vec3);

	std::printf("%s", (mat4.ToString() + '\n').c_str());
}
