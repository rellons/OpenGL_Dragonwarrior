// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

#include <common/shader.hpp>

int main(void)
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1024, 768, "Dragon", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	// Initialize GLEW
	glewExperimental = true; 
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	GLuint programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

	static const GLfloat g_vertex_buffer_data[] = {
		-0.75f, -0.2666666666666666f, 0.0f,
		-0.865f, -0.3866666666666667f, 0.0f,
		-0.645f, -0.46666666666666656f, 0.0f,
		-0.81f, -0.1333333333333333f, 0.0f,
		-0.79f, -0.32000000000000006f, 0.0f,
		-0.73f, -0.2533333333333334f, 0.0f,
		-0.645f, -0.46666666666666656f, 0.0f,
		-0.755f, -0.42666666666666675f, 0.0f,
		-0.815f, -0.5266666666666666f, 0.0f,
		-0.6699999999999999f, -0.26f, 0.0f,
		-0.655f, -0.06666666666666665f, 0.0f,
		-0.73f, -0.2533333333333334f, 0.0f,
		-0.63f, -0.46666666666666656f, 0.0f,
		-0.485f, -0.2466666666666666f, 0.0f,
		-0.73f, -0.2533333333333334f, 0.0f,
		-0.17000000000000004f, -0.52f, 0.0f,
		-0.485f, -0.2466666666666666f, 0.0f,
		-0.63f, -0.46666666666666656f, 0.0f,
		-0.17000000000000004f, -0.52f, 0.0f,
		-0.06499999999999995f, -0.2466666666666666f, 0.0f,
		-0.485f, -0.2466666666666666f, 0.0f,
		-0.17000000000000004f, -0.52f, 0.0f,
		0.3500000000000001f, -0.4933333333333334f, 0.0f,
		-0.06499999999999995f, -0.2466666666666666f, 0.0f,
		-0.14f, -0.7533333333333334f, 0.0f,
		-0.07999999999999996f, -0.5333333333333334f, 0.0f,
		-0.17000000000000004f, -0.52f, 0.0f,
		-0.06000000000000005f, -0.78f, 0.0f,
		0.0f, -0.54f, 0.0f,
		-0.07999999999999996f, -0.5333333333333334f, 0.0f,
		0.19999999999999996f, -0.7333333333333334f, 0.0f,
		0.2749999999999999f, -0.54f, 0.0f,
		0.19100000000000006f, -0.5f, 0.0f,
		0.2749999999999999f, -0.54f, 0.0f,
		0.30000000000000004f, -0.7f, 0.0f,
		0.3400000000000001f, -0.5f, 0.0f,
		0.3400000000000001f, -0.5f, 0.0f,
		0.351f, -0.1333333333333333f, 0.0f,
		-0.06499999999999995f, -0.2466666666666666f, 0.0f,
		0.3500000000000001f, -0.48f, 0.0f,
		0.8500000000000001f, -0.3600000000000001f, 0.0f,
		0.3400000000000001f, -0.2333333333333334f, 0.0f,
		0.835f, -0.3733333333333333f, 0.0f,
		0.98f, -0.1333333333333333f, 0.0f,
		0.675f, -0.27333333333333343f, 0.0f,
		-0.06499999999999995f, -0.2466666666666666f, 0.0f,
		0.351f, -0.1333333333333333f, 0.0f,
		0.1200000000000001f, 0.7133333333333334f, 0.0f,
		0.1200000000000001f, 0.7133333333333334f, 0.0f,
		0.351f, -0.1333333333333333f, 0.0f,
		0.44999999999999996f, 0.30666666666666664f, 0.0f,
		0.44999999999999996f, 0.30666666666666664f, 0.0f,
		0.73f, 0.6666666666666667f, 0.0f,
		0.1200000000000001f, 0.7133333333333334f, 0.0f,
		-0.06499999999999995f, -0.2466666666666666f, 0.0f,
		0.004999999999999893f, 0.11333333333333329f, 0.0f,
		-0.19499999999999995f, 0.6333333333333333f, 0.0f,
		-0.06499999999999995f, -0.2466666666666666f, 0.0f,
		-0.09999999999999998f, 0.033333333333333326f, 0.0f,
		-0.26f, -0.05333333333333323f, 0.0f,
		-0.26f, -0.05333333333333323f, 0.0f,
		-0.09999999999999998f, 0.033333333333333326f, 0.0f,
		-0.19499999999999995f, 0.6333333333333333f, 0.0f,
		-0.26f, -0.05333333333333323f, 0.0f,
		-0.19499999999999995f, 0.6333333333333333f, 0.0f,
		-0.35f, 0.10666666666666669f, 0.0f,
		-0.35f, 0.10666666666666669f, 0.0f,
		-0.19499999999999995f, 0.6333333333333333f, 0.0f,
		-0.30500000000000005f, 0.5533333333333333f, 0.0f,

	};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	do {

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);

		// Use shader
		glUseProgram(programID);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized
			0,                  // stride
			(void*)0            // array buffer offset
			);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 23 * 3); // 3 indices starting at 0 -> 1 triangle

		glDisableVertexAttribArray(0);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} 
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);


	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(programID);

	glfwTerminate();
	return 0;
}

