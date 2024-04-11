#include </opt/homebrew/Cellar/glfw/3.4/include/GLFW/glfw3.h>

using namespace std;

int main() {
  GLFWwindow* window;
  // Initialize GLFW
  if (!glfwInit()) {
    // Initialization failed
    return -1;
  }

  // Create a windowed mode window and its OpenGL context
  window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
  if (!window) {
    // Window creation failed
    glfwTerminate();
    return -1;
  }

  // Make the window's context current
  glfwMakeContextCurrent(window);

  // Loop until the user closes the window
  while (!glfwWindowShouldClose(window)) {
    // Render here

    // Swap front and back buffers
    glfwSwapBuffers(window);

    // Poll for and process events
    glfwPollEvents();
  }

  // Cleanup
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
