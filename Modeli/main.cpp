//BETMOBIL

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.hpp"
#include "model.hpp"



const unsigned int wWidth = 1200;
const unsigned int wHeight = 800;


unsigned int loadTexture(const char* path);


int main()
{
    if(!glfwInit())
    {
        std::cout << "GLFW fail!\n" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(wWidth, wHeight, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Window fail!\n" << std::endl;
        glfwTerminate();
        return -2;
    }
    glfwMakeContextCurrent(window);

    if (glewInit() !=GLEW_OK)
    {
        std::cout << "GLEW fail! :(\n" << std::endl;
        return -3;
    }


    float vertices[] =
    {  

    -1.0f, -0.5f,  0.0f,  0.0f,  0.0f, 1.0f,
     1.0f, -0.5f,  0.0f,  0.0f,  0.0f, 1.0f,
     1.0f,  0.5f,  0.0f,  0.0f,  0.0f, 1.0f,
     1.0f,  0.5f,  0.0f,  0.0f,  0.0f, 1.0f,
    -1.0f,  0.5f, 0.0f,  0.0f,  0.0f, 1.0f,
    -1.0f, -0.5f,  0.0f,  0.0f,  0.0f, 1.0f,
    };

    float podeok[] =
    {   

     0.0f, 0.5f,  0.001f,  0.0f,  0.0f, 1.0f,
     0.01f, 0.5f,  0.001f,  0.0f,  0.0f, 1.0f,
     0.0f, 0.9f,  0.001f,  0.0f,  0.0f, 1.0f,

     0.01f, 0.9f, 0.001f, 0.0f, 0.0f, 1.0f   ,
     0.0f, 0.9f,  0.001f,  0.0f,  0.0f, 1.0f,
     0.01f, 0.5f,  0.001f,  0.0f,  0.0f, 1.0f

    };

    float kazaljka[] =
    {
        -0.25f, -1.4f, 0.0011f, 0.0, 0.0, 1.0, 
        0.0f, -1.4f, 0.0011f, 0.0, 0.0, 1.0,
        -0.25f, -1.395f, 0.0011f, 0.0, 0.0, 1.0,

        -0.25f, -1.395f, 0.0011f, 0.0, 0.0, 1.0,
        -0.25f, -1.4f, 0.0011f, 0.0, 0.0, 1.0,
        0.0f, -1.395f, 0.0011f, 0.0, 0.0, 1.0


    };

    float sijalica[] =
    {
        -1.3, -0.5, 0.001,
        -1.2, -0.5, 0.001,
        -1.2, -0.4, 0.001,

        -1.2, -0.4, 0.001,
        -1.3, -0.4, 0.001,
        -1.3, -0.5, 0.001

    };

    float tahometar[] =
    {

     -0.4, -0.1,  0.001,   0.0, 0.0, 1.0,   1.0,1.0,
     0.8, -0.1,  0.001,   0.0,0.0,1.0,     0.0,1.0,  
     -0.4, 1.1,  0.001,  0.0,0.0,1.0,     1.0,0.0,

     0.8, -0.1,  0.001,   0.0,0.0,1.0,     0.0,1.0,
     0.8, 1.1,   0.001,   0.0, 0.0, 1.0,   0.0, 0.0,
     -0.4, 1.1,  0.001,  0.0,0.0,1.0,     1.0,0.0

    };

    float ime[] =
    {

     2.05, -2.0,  0.001,   0.0, 0.0, 1.0,   0.0,1.0,
     3.05, -2.0,  0.001,   0.0,0.0,1.0,     1.0,1.0,
     2.05, -1.8,  0.001,  0.0,0.0,1.0,     0.0,0.0,

     3.05, -2.0,  0.001,   0.0,0.0,1.0,     1.0,1.0,
     3.05, -1.8,   0.001,   0.0, 0.0, 1.0,   1.0, 0.0,
     2.05, -1.8,  0.001,  0.0,0.0,1.0,     0.0,0.0

    };

    float slepiMis[] =
    {
        -0.05f, -0.55f, 0.001f, 0.0f, 0.0f, 1.0f,
        0.05f, -0.57f, 0.001f, 0.0f, 0.0f, 1.0f,
        0.1f, -0.5f, 0.001f,  0.0f, 0.0f, 1.0f,


        0.05f, -0.57f, 0.001f, 0.0f, 0.0f, 1.0f,
        0.2f, -0.7f, 0.001f,  0.0f, 0.0f, 1.0f,
        0.1f, -0.5f, 0.001f,  0.0f, 0.0f, 1.0f,

        0.2f, -0.7f, 0.001f,  0.0f, 0.0f, 1.0f,
        0.3f, -0.7f, 0.001f,  0.0f, 0.0f, 1.0f,
        0.1f, -0.5f, 0.001f,  0.0f, 0.0f, 1.0f,


        0.2f, -0.7f, 0.001f,  0.0f, 0.0f, 1.0f,
        0.3f, -0.7f, 0.001f,  0.0f, 0.0f, 1.0f,
        0.4f, -0.5f, 0.001f,  0.0f, 0.0f, 1.0f,

        
        0.3f, -0.7f, 0.001f,  0.0f, 0.0f, 1.0f,
        0.45f, -0.57f, 0.001f, 0.0f, 0.0f, 1.0f,
        0.4f, -0.5f, 0.001f,  0.0f, 0.0f, 1.0f,

        0.45f, -0.57f, 0.001f, 0.0f, 0.0f, 1.0f,
        0.55f, -0.55f, 0.001f, 0.0f, 0.0f, 1.0f,
        0.4f, -0.5f, 0.001f,  0.0f, 0.0f, 1.0f
    };

    float slepiMisProstor[] =
    {
        1.0f, -0.9f, 0.0001f, 0.0f, 0.0f, 1.0f,
        2.5f, -0.9f, 0.0001f, 0.0f, 0.0f, 1.0f,
        1.0f, -0.3f, 0.0001f, 0.0f, 0.0f, 1.0f,

        2.5f, -0.9f, 0.0001f, 0.0f, 0.0f, 1.0f,
        2.5f, -0.3f, 0.0001f, 0.0f, 0.0f, 1.0f,
        1.0f, -0.3f, 0.0001f, 0.0f, 0.0f, 1.0f

    };

    float mesec[] =
    {
        2.0f, 2.0f, -4.0f,  1.0f, 1.0f,
        2.5f, 2.0f, -4.0f,  0.0f, 1.0f, 
        2.5f, 2.5f, -4.0f,  0.0f, 0.0f,

        2.5f, 2.5f, -4.0f,  0.0f, 0.0f,
        2.0f, 2.5f, -4.0f,  1.0f, 0.0f,
        2.0f, 2.0f, -4.0f,  1.0f, 1.0f


    };

    float put[] =
    {
        -33.0f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,     0.0f, 0.0f,
        33.0f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f,     1.0f, 0.0f,
        33.0f,  -0.5f, -60.0f,   0.0f, 1.0f, 0.0f,     1.0f, 1.0f,

        33.0f, -0.5f, -60.0f,   0.0f, 1.0f, 0.0f,      1.0f, 1.0f,
        -33.0f, -0.5f, -60.0f,  0.0f, 1.0f, 0.0f,      0.0f, 1.0f,
        -33.0f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,     0.0f, 0.0f

    };

    float kocka[] = {

         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
                 -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
                 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,

         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,

         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,



        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,

         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,


        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };

    



    unsigned int stride = (3 + 3) * sizeof(float);
    unsigned int stride1 = (3 + 3 +2) * sizeof(float);


    unsigned int VAO[11];
    glGenVertexArrays(11, VAO);


    unsigned int VBO[11];
    glGenBuffers(11, VBO);

    glBindVertexArray(VAO[9]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[9]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(sijalica), sijalica, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3* sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);



    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);



    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(podeok), podeok, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    glBindVertexArray(VAO[2]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(slepiMis), slepiMis, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    glBindVertexArray(VAO[3]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[3]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(slepiMisProstor), slepiMisProstor, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    glBindVertexArray(VAO[4]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[4]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(tahometar), tahometar, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride1, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride1, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,stride1, (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(VAO[10]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[10]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(ime), ime, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride1, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride1, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride1, (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    glBindVertexArray(VAO[5]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[5]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(kocka), kocka, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(VAO[6]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[6]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mesec), mesec, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(VAO[7]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[7]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(put), put, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(VAO[8]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[8]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(kazaljka), kazaljka, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)wWidth / (float)wHeight, 0.1f, 100.0f);

    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++ SEJDERI +++++++++++++++++++++++++++++++++++++++++++++++++
    //TABLA
    Shader tablaShader("tabla.vert", "tabla.frag");

    tablaShader.use();

    glm::mat4 modelPod = glm::mat4(1.0f);
    modelPod = glm::translate(modelPod, glm::vec3(0.0f, -2.0f, 0.0f));
    glm::mat4 modelTablaKretanje = modelPod;
    tablaShader.setMat4("uM", modelPod);



    tablaShader.setMat4("uP", projection);

    
    tablaShader.setVec3("uLight.dir", -3.0, -1.0, 1.0);


    tablaShader.setFloat("uMaterial.shine", 0.25 * 128);
    tablaShader.setVec3("uMaterial.kA", 0.25, 0.15, 0.05);
    tablaShader.setVec3("uMaterial.kD", 0.01, 0.01, 0.01);
    tablaShader.setVec3("uMaterial.kS", 0.5, 0.5, 0.5);
    
    tablaShader.setFloat("pointLight1.constant", 1.0f);
    tablaShader.setFloat("pointLight1.linear", 0.09f);
    tablaShader.setFloat("pointLight1.quadratic", 0.035f);


    ////////////////////////////////////////////////////////////////////////////////////////
    //PODEOK

    Shader podeokShader("podeok.vert", "tabla.frag");

    podeokShader.use();

    glm::mat4 modelPodeok = glm::mat4(1.0f);
    modelPodeok = glm::translate(modelPodeok, glm::vec3(0.0f, -1.2f, 0.0f));
    glm::mat4 modelPodeokKretanje = modelPodeok;
    podeokShader.setMat4("uM", modelPodeok);

    podeokShader.setMat4("uP", projection);

    podeokShader.setFloat("uMaterial.shine", 0.25 * 128);//zelena plastika
    podeokShader.setVec3("uMaterial.kA", 0, 0, 0);
    podeokShader.setVec3("uMaterial.kD", 0.1, 0.35, 0.1);
    podeokShader.setVec3("uMaterial.kS", 0.55, 0.45, 0.55);

    podeokShader.setFloat("pointLight1.constant", 1.0f);
    podeokShader.setFloat("pointLight1.linear", 0.09f);
    podeokShader.setFloat("pointLight1.quadratic", 0.035f);

    podeokShader.setVec3("uLight.dir", -3.0, -1.0, 1.0);

   



    ////////////////////////////////////////////////////////////////////////////////////////
    //SLEPI MIS

    Shader slepiMisShader("slepiMis.vert", "tabla.frag");

    slepiMisShader.use();

    glm::mat4 modelSM = glm::mat4(1.0f);
    modelSM = glm::translate(modelSM, glm::vec3(1.5f, -0.75f, 0.0f));
    slepiMisShader.setMat4("uM", modelSM);
    glm::mat4 modelSMKretanje = modelSM;

    slepiMisShader.setMat4("uP", projection);



    slepiMisShader.setVec3("uLight.dir", -3.0, -1.0, 1.0);


    slepiMisShader.setFloat("pointLight1.constant", 1.0f);
    slepiMisShader.setFloat("pointLight1.linear", 0.09f);
    slepiMisShader.setFloat("pointLight1.quadratic", 0.035f);


    slepiMisShader.setFloat("uMaterial.shine", 0.25 * 128);//zelena plastika
    slepiMisShader.setVec3("uMaterial.kA", 0, 0, 0);
    slepiMisShader.setVec3("uMaterial.kD", 0.65, 0.25, 0.55);
    slepiMisShader.setVec3("uMaterial.kS", 0.65, 0.35, 0.55);

    //////////////////////////////////////////////////////////////////////////////////////////////
    //VOLAN


    Model volan("res/merc steering.obj");

    Shader unifiedShader("basic.vert", "basic.frag");


    unifiedShader.use();


    unifiedShader.setMat4("uP", projection);

    unifiedShader.setVec3("uLight.dir", -3.0, -1.0, 1.0);

    unifiedShader.setFloat("pointLight1.constant", 1.0f);
    unifiedShader.setFloat("pointLight1.linear", 0.09f);
    unifiedShader.setFloat("pointLight1.quadratic", 0.035f);

    unifiedShader.setFloat("pointLight2.constant", 1.0f);
    unifiedShader.setFloat("pointLight2.linear", 0.09f);
    unifiedShader.setFloat("pointLight2.quadratic", 0.035f);

    unifiedShader.setFloat("pointLight3.constant", 1.0f);
    unifiedShader.setFloat("pointLight3.linear", 0.09f);
    unifiedShader.setFloat("pointLight3.quadratic", 0.035f);

    unifiedShader.setFloat("pointLight4.constant", 1.0f);
    unifiedShader.setFloat("pointLight4.linear", 0.09f);
    unifiedShader.setFloat("pointLight4.quadratic", 0.035f);


    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-2.0f, -2.0f, 0.0f));
    unifiedShader.setMat4("uM", model);
    glm::mat4 modelKretanje = model;
    
    ///////////////////////////////////////////////
    //TAHOMETAR
    Shader tahometarShader("tahometar.vert", "tahometar.frag");

    tahometarShader.use();
    tahometarShader.setVec3("uLight.dir", -3.0, -1.0, 1.0);

    tahometarShader.setFloat("pointLight1.constant", 1.0f);
    tahometarShader.setFloat("pointLight1.linear", 0.09f);
    tahometarShader.setFloat("pointLight1.quadratic", 0.035f);


    tahometarShader.setMat4("uP", projection);


    glm::mat4 modelTah = glm::mat4(1.0f);
    modelTah = glm::translate(modelTah, glm::vec3(0.0f, -1.9f, 0.0f));
    tahometarShader.setMat4("uM", modelTah);
    glm::mat4 modelTahKretanje = modelTah;

    unsigned checkerTexture = loadTexture("res/tablameraca.png"); //Ucitavamo teksturu
    glBindTexture(GL_TEXTURE_2D, checkerTexture); //Podesavamo teksturu
    glGenerateMipmap(GL_TEXTURE_2D); //Generisemo mipmape 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);//S = U = X    GL_REPEAT, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);// T = V = Y
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);  //GL_NEAREST, GL_LINEAR
    glBindTexture(GL_TEXTURE_2D, 0);

    tahometarShader.setInt("uTex", 0);
    ////////////////////////////////////////////////
    //IME
    Shader imeShader("ime.vert", "ime.frag");
  
   imeShader.use();
    imeShader.setVec3("uLight.dir", -3.0, -1.0, 1.0);

    imeShader.setFloat("pointLight1.constant", 1.0f);
    imeShader.setFloat("pointLight1.linear", 0.09f);
    imeShader.setFloat("pointLight1.quadratic", 0.035f);


    imeShader.setMat4("uP", projection);


    glm::mat4 modelIme = glm::mat4(1.0f);
    glm::mat4 modelImeKretanje = modelIme;
    imeShader.setMat4("uM", modelIme);

  unsigned imeTexture = loadTexture("res/m.png"); //Ucitavamo teksturu
  glBindTexture(GL_TEXTURE_2D, imeTexture); //Podesavamo teksturu
    glGenerateMipmap(GL_TEXTURE_2D); //Generisemo mipmape 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);//S = U = X    GL_REPEAT, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);// T = V = Y
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);  //GL_NEAREST, GL_LINEAR
    glBindTexture(GL_TEXTURE_2D, 0);

    tahometarShader.setInt("uTex", 0);

    ///////////////////////////////////////////////
    //ZGRADA
    Shader zgradaShader("kocka.vert", "kocka.frag");

    zgradaShader.use();

    unsigned int diffuseMap = loadTexture("res/container.png");
    unsigned int specularMap = loadTexture("res/container2.png");

    unsigned int diffuseMapPut = loadTexture("res/beton1.png");
    unsigned int specularMapPut = loadTexture("res/beton2.png");

    zgradaShader.setInt("uMaterial.diffuse", 0);
    zgradaShader.setInt("uMaterial.specular", 1);

    zgradaShader.setVec3("uLight.dir", -3.0,-1.0,1.0);


    zgradaShader.setFloat("uMaterial.shine", 25.0f);

    zgradaShader.setFloat("spotLight.constant", 1.25f);
    zgradaShader.setFloat("spotLight.linear", 0.065f);
    zgradaShader.setFloat("spotLight.quadratic", 0.013f);
    zgradaShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(4.8f)));
    zgradaShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(5.7f)));


    zgradaShader.setFloat("spotLight2.constant", 1.25f);
    zgradaShader.setFloat("spotLight2.linear", 0.065f);
    zgradaShader.setFloat("spotLight2.quadratic", 0.013f);
    zgradaShader.setFloat("spotLight2.cutOff", glm::cos(glm::radians(4.8f)));
    zgradaShader.setFloat("spotLight2.outerCutOff", glm::cos(glm::radians(5.7f)));





    zgradaShader.setMat4("uP", projection);


    

    /////////////////////////////////////////
    //MESEC

    Shader mesecShader("mesec.vert", "mesec.frag");

    mesecShader.use();
    unsigned int mesecTekstura = loadTexture("res/5559_betmen-znak.png");
    glBindTexture(GL_TEXTURE_2D, mesecTekstura); 
    glGenerateMipmap(GL_TEXTURE_2D);  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);  
    glBindTexture(GL_TEXTURE_2D, 0);
    mesecShader.setInt("uTex", 0);


    mesecShader.setMat4("projection", projection);

  /*  glm::mat4 modelMes = glm::mat4(1.0f);
    glm::mat4 modelMeswc = modelMes;

    mesecShader.setMat4("model", modelMes);
    */
   
   
    /////////////////////////////////////////
    //KAZALJKA
    Shader kazaljkaShader("kazaljka.vert", "kazaljka.frag");

    kazaljkaShader.use();

    glm::mat4 modelK = glm::mat4(1.0f);
    kazaljkaShader.setMat4("uM", modelK);
    glm::mat4 modelKKretanje = modelK;
    kazaljkaShader.setMat4("uP", projection);

    //////////////////////////////////////////
    //SIJALICA
    Shader sijalicaShader("sijalica.vert", "sijalica.frag");
    sijalicaShader.use();
    sijalicaShader.setMat4("uP", projection);
    ////////////////////////////////////////////
    ///////SIJALICA2
    Shader sijalica2Shader("sijalica2.vert", "sijalica2.frag");
    sijalica2Shader.use();
    sijalica2Shader.setMat4("uP", projection);

    //////////////////////////////////////////
    ///SIJALICA3
    Shader sijalica3Shader("sijalica3.vert", "sijalica3.frag");
    sijalica3Shader.use();
    sijalica3Shader.setMat4("uP", projection);


    glClearColor(0.0, 0.0, 0.0, 1.0);

    glm::vec3 zgradePositions[] = {
    glm::vec3(-15.0f,  0.0f,  -3.0f),
    glm::vec3(-15.0f,  0.0f, -5.0f),
    glm::vec3(15.0f, 0.0f, -3.0f),
    glm::vec3(15.0f, 0.0f, -5.0f),
    glm::vec3(15.0f, 0.0f, -7.0f),
    glm::vec3(-15.0f, 0.0f, -7.0f)

    };




    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    double ubrzanje = 0;
    bool usaoJednom = false;
    bool upaljenA = false;
    bool upaljenW = false;
    bool upaljenS = false;
    bool upaljenD = false;
    double presao = 0;
    double podeoka = 1;
    int predjenihpodeoka = 1;
    double prethodni = 0;
    double prelazak = 0;
    int stepen = 0;
    float pomerajY = 0.0;
    float pomerajX = 0.0;
    float providnostMisa = 1.0;
    float pomeraj = 0.0;
    float korak=0.001;
    float levoadesno = 0.0;
    float koraklevodesno = 0.00005;
    float stepenRotacije = 0;
    float korakRotacije = 0.01;
    float pomerenoPodeoka = 1;
    float amb = 0.0;
    float dif = 0.0;
    float difg = 0.0;
    float ambCS = 0.0;
    float difCS = 0.0;
    float crvena = 0.0;
    float plava = 0.0;
    float ambBS = 0.0;
    float difBS = 0.0;
    float rgb = 0;
    char prethodniTaster = '.';
    float ulamb = 0.1;
    float uldif = 0.3;
    float ulspec = 0.8;
    float tlamb = 0.15;
    float tldif = 0.5;
    float tlspec = 0.7;
    float ambCNV = 0.0;
    float ambBNV = 0.0;
    float difCNV = 0.0;
    float difBNV = 0.0;
    bool nm = false;
    bool nv = false;
    float kazaljkaUgao = 0.0f;
    float ldPolozaj = 0.0f;

 
    float angle = 0;


    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);


        if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
        {
            ulamb = 0.0;
            uldif = 0.0;
            ulspec = 0.0;
            tlamb = 0.0;
            tldif = 0.0;
            tlspec = 0.0;
            ambCNV = 0.2;
            difCNV = 0.85;
            ambBNV = 0.27;
            difBNV = 0.7;
            nv = true;
            if (nm)
            {
                difg = 1.0;
                dif = 0.0;
            }


        }

        if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        {
            ulamb = 0.1;
            uldif = 0.3;
            ulspec = 0.8;
            nv = false;
            tlamb = 0.15;
            tldif = 0.5;
            tlspec = 0.7;
            ambCNV = 0.0;
            difCNV = 0.0;
            ambBNV = 0.0;
            difBNV = 0.0;
            if (nm)
            {
                difg = 1.0;
                dif = 1.0;
            }
            


        }

     

        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE)
        {
            upaljenS = false;
            if (prethodniTaster == 's')
            {
                    if ((korak - 0.000005 > 0) && pomeraj - korak > -16 * abs(cos(angle)))         
                    {
                        if (pomeraj - korak > -15)
                        {
                            pomeraj -= korak;
                            korak -= 0.000005;
                        }
                    }
            }
            if (prethodniTaster == 's')
            {
                if (kazaljkaUgao - 0.01 >= 0)
                    kazaljkaUgao -= 0.01f;
            }
        }


        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        {

                angle += 0.0005f;

        }

        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        {

            angle -= 0.0005f;

        }

   /*     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            upaljenW = true;
            ubrzanje += 0.0001;
            usaoJednom = true;
            if (pomeraj + korak <15 && ldPolozaj < 30 - abs(ldPolozaj))
            {
                pomeraj += korak;
                ldPolozaj += angle / abs(angle) * pomeraj * abs(sin(angle));
                korak += 0.000001;

                if (pomeraj + korak < 15)
                {
                    pomeraj += korak;
                    korak += 0.000001;

                    if (kazaljkaUgao + 0.0035 <= 23.5)
                        kazaljkaUgao += 0.0035f;
                }
                if (kazaljkaUgao + 0.0035 <= 23.5)
                    kazaljkaUgao += 0.0035f;
            }
            if (pomerajY + 0.001 < 0.2)
                pomerajY += 0.001;
           
            prethodniTaster = 'w';



        }*/


        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            upaljenW = true;
            ubrzanje += 0.0001;
            usaoJednom = true;
            if (pomeraj + korak < 16 *abs(cos(angle)))
            {
                //pomeraj += korak;
                //ldPolozaj += angle / abs(angle) * pomeraj * abs(sin(angle));
                //korak += 0.000001;

                if (pomeraj + korak < 11)
                {
                    pomeraj += korak;
                    korak += 0.000001;

                    if (kazaljkaUgao + 0.0035 <= 23.5)
                        kazaljkaUgao += 0.0035f;
                }
               
            }
            if (pomerajY + 0.001 < 0.2)
                pomerajY += 0.001;

            prethodniTaster = 'w';



        }

        if ((upaljenA==0) && (upaljenD==0) && (upaljenS==0) && (upaljenW==0) && usaoJednom)
        {
            if (ubrzanje - 0.0005 >= 0)
                ubrzanje -= 0.0005;
            else
                ubrzanje = 0;
        }





        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            ubrzanje += 0.0001;
            upaljenS = true;
            usaoJednom = true;
            if (pomerajY - 0.001 > -0.2)
                pomerajY -= 0.001;
            if (pomeraj - korak> -16*abs(cos(angle)))
            if (pomeraj - korak > -15)
            {
                pomeraj -= korak;
                korak += 0.000001;
                if (kazaljkaUgao + 0.0035 <= 23.5)
                    kazaljkaUgao += 0.0035f;
            }
            prethodniTaster = 's';



            

        }

        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            if (pomerajX - 0.001 > -0.45)
                pomerajX -= 0.001;
            upaljenA = true;
            ubrzanje += 0.00005;
            usaoJednom = true;
            if (levoadesno + koraklevodesno < 3.8)
            {
                levoadesno += koraklevodesno;
                koraklevodesno += 0.0000001;

                if (kazaljkaUgao + 0.002f <= 23.5)
                    kazaljkaUgao += 0.002f;
            }
            prethodniTaster = 'a';
            


        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE)
        {
            upaljenA = false;
            if (prethodniTaster == 'a')
            {
               
                    if ((levoadesno + koraklevodesno < 3.8) && (koraklevodesno - 0.000001 > 0))
                    {
                        levoadesno += koraklevodesno;
                        koraklevodesno -= 0.000001;
                    }
                
            }
            if (prethodniTaster == 'a')
            {
                if (kazaljkaUgao - 0.005 >= 0)
                    kazaljkaUgao -= 0.005f;
            }

        }

        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE)
        {
            upaljenD = false;

            if (prethodniTaster == 'd')
            {
                if ((levoadesno - koraklevodesno > -3.8) && (koraklevodesno- 0.000001>0))
                {
                    levoadesno -= koraklevodesno;
                    koraklevodesno -= 0.000001;
                }
            }
            if (prethodniTaster == 'd')
            {
                if (kazaljkaUgao - 0.002 >= 0)
                    kazaljkaUgao -= 0.002f;
            }

        }

        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            ubrzanje += 0.00005;
            upaljenD = true;
            usaoJednom = true;
            if (pomerajX + 0.001 < 0.45)
                pomerajX += 0.001;
            if (levoadesno - koraklevodesno > -3.8)
            {
                levoadesno -= koraklevodesno;
                koraklevodesno += 0.0000001;
                if (kazaljkaUgao + 0.002 <= 23.5)
                    kazaljkaUgao += 0.002f;
            }
            prethodniTaster = 'd';

        }

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE)
        {
            upaljenW = false;
            if (prethodniTaster == 'w')
            {
                if ((korak - 0.000005 > 0) && (pomeraj + korak < 16 * abs(cos(angle))))
                {
                    if (pomeraj + korak < 11)
                    {
                        pomeraj += korak;
                        korak -= 0.000005;
                    }
                }

            }
            if (prethodniTaster == 'w')
            {
                if (kazaljkaUgao - 0.01 >= 0)
                    kazaljkaUgao -= 0.01f;
            }
        }







        if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
        {
            providnostMisa = 0.7;
        }

        if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
        {
            providnostMisa = 1.0;
        }







        prelazak = presao + ubrzanje;

        if (prelazak > (double)predjenihpodeoka*1000)
        {
            predjenihpodeoka += 1;

            if (podeoka + 1 <= 11)
            {
                podeoka += 1;
                pomerenoPodeoka = podeoka * 10;

            }
            else
            {
                podeoka = 1;
                pomerenoPodeoka = 0.1;

            }
        }

        presao = prelazak;
        

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



        if ((ubrzanje > 0) && (ubrzanje <= 0.1))
            stepen = 1;
        else if ((ubrzanje > 0.1) && (ubrzanje <= 0.5))
            stepen = 2;
        else if ((ubrzanje > 0.5) && (ubrzanje <= 1.5))
            stepen = 3;
        else if ((ubrzanje > 1.5) && (ubrzanje <= 3))
            stepen = 4;
        else if (ubrzanje > 3 && ubrzanje <= 6)
            stepen = 5;
        else
            stepen = 0;



        /////////////////////////////////////////////////////////////////////////
        glm::vec3 cameraPos = glm::vec3(0.0f - levoadesno, 0.0f, 5.0f - pomeraj);
        glm::vec3 cameraFront = glm::vec3(0.0f - levoadesno, 0.0f, -10.0f );

        glm::mat4 view = glm::lookAt(cameraPos, cameraFront, glm::vec3(0.0f, 1.0f, 0.0f));






        if (stepen == 2)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            glEnable(GL_PROGRAM_POINT_SIZE);
            glPointSize(8);

        }
        else if (stepen == 1)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            glEnable(GL_PROGRAM_POINT_SIZE);
            glPointSize(4);
        }
        /////////////////////////////////////////////////////////
        //SLEPI MIS
       
        slepiMisShader.use();
        slepiMisShader.setFloat("providnost", providnostMisa);

        slepiMisShader.setVec3("pointLight1.position", glm::vec3(0.0f - levoadesno, 0.5f, 0.5f - pomeraj));
        slepiMisShader.setVec3("uLight.kA", ulamb, 0.1, ulamb);
        slepiMisShader.setVec3("uLight.kD", uldif, 0.3, uldif);
        slepiMisShader.setVec3("uLight.kS", ulspec, 0.8, ulspec);

        slepiMisShader.setVec3("pointLight1.ambient", tlamb, 0.15, tlamb);
        slepiMisShader.setVec3("pointLight1.diffuse", tldif, 0.5, tldif);
        slepiMisShader.setVec3("pointLight1.specular", tlspec, 0.7, tlspec);
         
        slepiMisShader.setMat4("uV", view);
        slepiMisShader.setVec3("uViewPos", cameraPos );
        modelSM = glm::translate(modelSMKretanje, glm::vec3(0.0f - levoadesno , 0.0f, 0.0f - pomeraj));
       
        slepiMisShader.setMat4("uM", modelSM);

        glBindVertexArray(VAO[2]);
        glDrawArrays(GL_TRIANGLES, 0, 18);
        slepiMisShader.setFloat("pomerajY", pomerajY);
        slepiMisShader.setFloat("pomerajX", pomerajX);


        if (stepen > -1)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

            ////////////////////////////////////////////////////////////////
            //ZGRADE
            zgradaShader.use();

            zgradaShader.setMat4("uV", view);

            zgradaShader.setVec3("uViewPos", cameraPos);

            zgradaShader.setVec3("uLight.kA", ulamb, 0.1, ulamb);
            zgradaShader.setVec3("uLight.kD", uldif, 0.3, uldif);
            zgradaShader.setVec3("uLight.kS", ulspec, 0.8, ulspec);

            zgradaShader.setVec3("spotLight.position", glm::vec3(0.0f - levoadesno - 1.7, 0.2f, 2.0f - pomeraj));
            zgradaShader.setVec3("spotLight.direction", 0.0f - levoadesno - 1.7, -0.65f, -5.0f);

            zgradaShader.setVec3("spotLight2.position", glm::vec3(0.0f - levoadesno + 1.7, 0.2f, 2.0f - pomeraj));
            zgradaShader.setVec3("spotLight2.direction", glm::vec3(0.0f - levoadesno + 1.7, -0.65f, -5.0f));



            if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
            {
                amb = 0.2f;
                dif = 1.0f;
                difg = 1.0f;
                if (nv)
                {
                    dif = 0.0f;
                }
                nm = true;

            }
            if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
            {
                amb = 0.0f;
                dif = 0.0f;
                difg = 0.0f;
                nm = false;
            }

            zgradaShader.setVec3("spotLight.ambient", amb, amb, amb);
            zgradaShader.setVec3("spotLight.diffuse", dif, difg, dif);
            zgradaShader.setVec3("spotLight.specular", dif, difg, dif);

            zgradaShader.setVec3("spotLight2.ambient", amb, amb, amb);
            zgradaShader.setVec3("spotLight2.diffuse", dif, difg, dif);
            zgradaShader.setVec3("spotLight2.specular", dif, dif, dif);

            zgradaShader.setVec3("spotLight3.ambient", 0.0, 0.0, 0.0);
            zgradaShader.setVec3("spotLight3.diffuse", 0.0, 0.0, 0.0);
            zgradaShader.setVec3("spotLight3.specular", 0.0, 0.0, 0.0);

            zgradaShader.setVec3("spotLight4.ambient", 0.0, 0.0, 0.0);
            zgradaShader.setVec3("spotLight4.diffuse", 0.0, 0.0, 0.0);
            zgradaShader.setVec3("spotLight4.specular", 0.0, 0.0, 0.0);

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, diffuseMap);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, specularMap);
            glBindVertexArray(VAO[5]);


            for (unsigned int i = 0; i < 6; i++)
            {
                glm::mat4 modelZgr = glm::mat4(1.0f);
                modelZgr = glm::rotate(modelZgr, angle, glm::vec3(0.0f, 3.0f, 0.0f));

                modelZgr = glm::translate(modelZgr, zgradePositions[i]);
            //    modelZgr = glm::translate(modelZgr, cameraPos);


                modelZgr = glm::scale(modelZgr, glm::vec3(4.0f, 4.0f, 1.0f));
                zgradaShader.setMat4("uM", modelZgr);
                glDrawArrays(GL_TRIANGLES, 0, 36);
            }
            ///////////////////////////////////////////////////////////////////////
            //PUT
            zgradaShader.use();



            glm::mat4 modelPut = glm::mat4(1.0f);
            modelPut = glm::rotate(modelPut, angle, glm::vec3(0.0f, 1.0f, 0.0f));

            modelPut = glm::translate(modelPut, glm::vec3(0.0, -1.7, 0.0));
          //  modelPut = glm::translate(modelPut, cameraPos);

            zgradaShader.setMat4("uM", modelPut);


            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, diffuseMapPut);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, specularMapPut);
            glBindVertexArray(VAO[7]);
            glDrawArrays(GL_TRIANGLES, 0, 6);

            /////////////////////////////////////////////////////////////////////////
            //MESEC



            mesecShader.use();
            glm::mat4 modelMes = glm::mat4(1.0f);
            modelMes = glm::rotate(modelMes, angle, glm::vec3(0.0, 1.0, 0.0));
          //  modelMes = glm::translate(modelMes, cameraPos);

            mesecShader.setMat4("model", modelMes);
            mesecShader.setMat4("uM", modelMes);
            mesecShader.setMat4("view", view);
            glBindVertexArray(VAO[6]);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, mesecTekstura);
            glDrawArrays(GL_TRIANGLES, 0, 6);

            /////////////////////////////////////////////////////////////////////////////
            //TAHOMETAR
            tahometarShader.use();
            tahometarShader.setVec3("pointLight1.position", glm::vec3(0.0f - levoadesno, 0.5f, 0.5f - pomeraj));
            tahometarShader.setVec3("pointLight1.ambient", tlamb, 0.15, tlamb);
            tahometarShader.setVec3("pointLight1.diffuse", tldif, 0.5, tldif);
            tahometarShader.setVec3("pointLight1.specular", tlspec, 0.7, tlspec);
            tahometarShader.setVec3("uLight.kA", ulamb, 0.1, ulamb);
            tahometarShader.setVec3("uLight.kD", uldif, 0.3, uldif);
            tahometarShader.setVec3("uLight.kS", ulspec, 0.8, ulspec);
            tahometarShader.setMat4("uV", view);

            tahometarShader.setVec3("uViewPos", cameraPos);
            modelTah = glm::translate(modelTahKretanje, glm::vec3(0.0f - levoadesno-0.21 , 0.0f, 0.0f - pomeraj));

            tahometarShader.setMat4("uM", modelTah);
            glBindVertexArray(VAO[4]);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, checkerTexture);
            glDrawArrays(GL_TRIANGLES, 0, 6);
            ////////////////////////////////////////////////////////////////////////////
            // IME
            imeShader.use();
            imeShader.setVec3("pointLight1.position", glm::vec3(0.0f - levoadesno, 0.5f, 0.5f - pomeraj));
            imeShader.setVec3("pointLight1.ambient", tlamb, 0.15, tlamb);
            imeShader.setVec3("pointLight1.diffuse", tldif, 0.5, tldif);
            imeShader.setVec3("pointLight1.specular", tlspec, 0.7, tlspec);
            imeShader.setVec3("uLight.kA", ulamb, 0.1, ulamb);
            imeShader.setVec3("uLight.kD", uldif, 0.3, uldif);
            imeShader.setVec3("uLight.kS", ulspec, 0.8, ulspec);
            imeShader.setMat4("uV", view);

            imeShader.setVec3("uViewPos", cameraPos);
            modelIme = glm::translate(modelImeKretanje, glm::vec3(0.0f - levoadesno, 0.0f, 0.0f - pomeraj));

            imeShader.setMat4("uM", modelIme);
            glBindVertexArray(VAO[10]);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, imeTexture);
            glDrawArrays(GL_TRIANGLES, 0, 6);






            /////////////////////////////////////////////////////////////////////////////
            //VOLAN
            if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
            {
                ambCS = 0.05;
                difCS = 1.0;
                crvena = 1.0;
            }
            if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
            {
                ambCS = 0.0;
                difCS = 0.0;
                crvena = 0.0;
            }
            if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
            {
                ambBS = 0.05;
                difBS = 1.0;
                plava = 1.0;
            }
            if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
            {
                ambBS = 0.0;
                difBS = 0.0;
                plava = 0.0;
            }

            float punazuta = abs(sin(glfwGetTime()));
            float intenzitetZute = (punazuta * float(stepen)) / 4;

            unifiedShader.use();
            unifiedShader.setVec3("pointLight1.position", glm::vec3(-1.3f-levoadesno, -0.5f, 0.001f-pomeraj));

          
            unifiedShader.setVec3("pointLight3.position", glm::vec3(-1.3f - levoadesno - 1, -0.5f, 0.001f - pomeraj));
            unifiedShader.setVec3("pointLight2.position", glm::vec3(-1.3f - levoadesno-0.5f, -0.5f, 0.001f - pomeraj));
            if (!nv)
            {
                unifiedShader.setVec3("pointLight1.ambient", ambCS, 0.0f, 0.0f);
                unifiedShader.setVec3("pointLight1.diffuse", difCS, 0.0f, 0.0f);
                unifiedShader.setVec3("pointLight1.specular", difCS, difCS, difCS);
                unifiedShader.setVec3("pointLight2.ambient", 0.0f, 0.0f, ambBS);
                unifiedShader.setVec3("pointLight2.diffuse", 0.0f, 0.0f, difBS);
                unifiedShader.setVec3("pointLight2.specular", difBS, difBS, difBS);
            }
            else
            {
                unifiedShader.setVec3("pointLight1.ambient", 0.0f, ambCNV, 0.0f);
                unifiedShader.setVec3("pointLight1.diffuse", ambCNV, difCNV, 0.0f);
                unifiedShader.setVec3("pointLight1.specular", difCS, difCS, difCS);

                unifiedShader.setVec3("pointLight2.ambient", 0.0f, ambBNV, 0.0f);
                unifiedShader.setVec3("pointLight2.diffuse", 0.0f, difBNV, ambBNV);
                unifiedShader.setVec3("pointLight2.specular", difBS, difBS, difBS);
            }
            unifiedShader.setVec3("pointLight3.ambient", 0.0, intenzitetZute, 0.0f);
            unifiedShader.setVec3("pointLight3.diffuse", 0.0, punazuta, 0.0);
            unifiedShader.setVec3("pointLight3.specular", 0.0, punazuta, punazuta);
            unifiedShader.setVec3("pointLight4.position", glm::vec3(0.0f - levoadesno, 0.5f, 0.5f - pomeraj));
            unifiedShader.setVec3("pointLight4.ambient", tlamb, 0.15, tlamb);
            unifiedShader.setVec3("pointLight4.diffuse", tldif, 0.5, tldif);
            unifiedShader.setVec3("pointLight4.specular", tlspec, 0.7, tlspec);

            unifiedShader.setVec3("uLight.kA", ulamb, 0.1, ulamb);
            unifiedShader.setVec3("uLight.kD", uldif, 0.3, uldif);
            unifiedShader.setVec3("uLight.kS", ulspec, 0.8, ulspec);

            unifiedShader.setMat4("uV", view);
            unifiedShader.setVec3("uViewPos", cameraPos);
            model = glm::translate(modelKretanje, glm::vec3(0.0f- levoadesno, 0.0f, 0.0f - pomeraj));
            model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
            unifiedShader.setMat4("uM", model);
            volan.Draw(unifiedShader);

            
            //KAZALJKA
            kazaljkaShader.use();
            kazaljkaShader.setBool("nv", nv);
            rgb = abs(sin(glfwGetTime()));
            kazaljkaShader.setFloat("u", rgb);

            kazaljkaShader.setMat4("uV", view);
            kazaljkaShader.setVec3("uViewPos", cameraPos);

            modelK = glm::translate(modelKKretanje, glm::vec3(0.0f - levoadesno, 0.0f, 0.0f - pomeraj));

            modelK = glm::translate(modelK, glm::vec3(0.0f + 0.25f, 0.0f, 0.0f));
            modelK = glm::rotate(modelK, glm::radians(-kazaljkaUgao), glm::vec3(0.0f, 0.0f, 0.011f));
            if (kazaljkaUgao > 18.5)
                modelK = glm::translate(modelK, glm::vec3(0.0f + 0.25f, 0.0f, 0.0f));
            else if (kazaljkaUgao > 17)
                modelK = glm::translate(modelK, glm::vec3(0.0f + 0.21f, 0.0f, 0.0f));
            else if (kazaljkaUgao > 15)
                modelK = glm::translate(modelK, glm::vec3(0.0f + 0.14f, 0.0f, 0.0f));
            else if (kazaljkaUgao > 13)
                modelK = glm::translate(modelK, glm::vec3(0.0f + 0.08f, 0.0f, 0.0f));
            else if (kazaljkaUgao > 11)
                modelK = glm::translate(modelK, glm::vec3(0.0f + 0.02f, 0.0f, 0.0f));
            else if (kazaljkaUgao > 9)
                modelK = glm::translate(modelK, glm::vec3(0.0f - 0.02f, 0.0f, 0.0f));
            else if (kazaljkaUgao > 7)
                modelK = glm::translate(modelK, glm::vec3(0.0f - 0.07f, 0.0f, 0.0f));
            else if (kazaljkaUgao > 6)
                modelK = glm::translate(modelK, glm::vec3(0.0f - 0.13f, 0.0f, 0.0f));
            else if (kazaljkaUgao > 5)
                modelK = glm::translate(modelK, glm::vec3(0.0f - 0.17f, 0.0f, 0.0f));
            else if(kazaljkaUgao>3.5)
                 modelK = glm::translate(modelK, glm::vec3(0.0f - 0.19f, 0.0f, 0.0f));
            else if (kazaljkaUgao > 2.0)
                modelK = glm::translate(modelK, glm::vec3(0.0f - 0.23f, 0.0f, 0.0f));
            else
                modelK = glm::translate(modelK, glm::vec3(0.0f - 0.25f, 0.0f, 0.0f));





            kazaljkaShader.setMat4("uM", modelK);
            kazaljkaShader.setFloat("levodesno", levoadesno);
            glBindVertexArray(VAO[8]);
            glDrawArrays(GL_TRIANGLES, 0, 6);

            /////////////////////////////////////////////////////////////////////
            //TABLA

            tablaShader.use();
            tablaShader.setFloat("providnost", 1.0);
            tablaShader.setFloat("uMaterial.shine", 0.25 * 128);
            tablaShader.setVec3("uMaterial.kA", 0.25, 0.15, 0.05);
            tablaShader.setVec3("uMaterial.kD", 0.01, 0.01, 0.01);
            tablaShader.setVec3("uMaterial.kS", 0.5, 0.5, 0.5);
            tablaShader.setVec3("pointLight1.position", glm::vec3(0.0f - levoadesno, 0.5f, 0.5f - pomeraj));

            tablaShader.setVec3("uLight.kA", ulamb, 0.1, ulamb);
            tablaShader.setVec3("uLight.kD", uldif, 0.3, uldif);
            tablaShader.setVec3("uLight.kS", ulspec, 0.8, ulspec);

            tablaShader.setVec3("pointLight1.ambient", tlamb, 0.15, tlamb);
            tablaShader.setVec3("pointLight1.diffuse", tldif, 0.5, tldif);
            tablaShader.setVec3("pointLight1.specular", tlspec, 0.7, tlspec);

            tablaShader.setMat4("uV", view);

            tablaShader.setVec3("uViewPos", cameraPos);

            modelPod = glm::translate(modelTablaKretanje, glm::vec3(0.0f-levoadesno, 0.0f, 0.0f - pomeraj ));
            modelPod = glm::scale(modelPod, glm::vec3(3.5f, 3.5f, 3.5f));
            tablaShader.setMat4("uM", modelPod);
            glBindVertexArray(VAO[0]);
            glDrawArrays(GL_TRIANGLES, 0, 6);
            /////////////////////////////////////////////////////////////////////
            //STAKLO


            tablaShader.use();
            tablaShader.setFloat("providnost", 0.15);
            tablaShader.setFloat("uMaterial.shine", 0.25 * 128);
            tablaShader.setVec3("uMaterial.kA", 0.0, 0.0, 0.0);
            tablaShader.setVec3("uMaterial.kD", 0.588235, 0.670588, 0.959412);
            tablaShader.setVec3("uMaterial.kS", 0.0, 0.0, 0.1);
            tablaShader.setVec3("pointLight1.position", glm::vec3(0.0f - levoadesno, 0.5f, 0.5f - pomeraj));

            tablaShader.setVec3("uLight.kA", ulamb, 0.1, ulamb);
            tablaShader.setVec3("uLight.kD", uldif, 0.3, uldif);
            tablaShader.setVec3("uLight.kS", ulspec, 0.8, ulspec);

            tablaShader.setVec3("pointLight1.ambient", tlamb, 0.15, tlamb);
            tablaShader.setVec3("pointLight1.diffuse", tldif, 0.5, tldif);
            tablaShader.setVec3("pointLight1.specular", tlspec, 0.7, tlspec);

            tablaShader.setMat4("uV", view);

            tablaShader.setVec3("uViewPos", cameraPos);

            glm::mat4 modelStaklo = glm::mat4(1.0f);
            modelStaklo = glm::translate(modelStaklo, glm::vec3(0.0f - levoadesno,0.5f, 0.0f - pomeraj));
            modelStaklo = glm::scale(modelStaklo, glm::vec3(3.5f, 2.1f, 3.5f));
            tablaShader.setMat4("uM", modelStaklo);
            glBindVertexArray(VAO[0]);
            glDrawArrays(GL_TRIANGLES, 0, 6);





            ///////////////////////////////////////////////////////////////
            //MIS POZADI
            tablaShader.setFloat("uMaterial.shine", 0.25 * 128);
            tablaShader.setVec3("uMaterial.kA", 0, 0, 0);
            tablaShader.setVec3("uMaterial.kD", 0.5, 0.35, 0.0);
            tablaShader.setVec3("uMaterial.kS", 0.6, 0.6, 0.5);

           
  
            glm::mat4 modelSMP = glm::mat4(1.0f);
            modelSMP = glm::translate(modelSMP, glm::vec3(0.0f, -0.75f, 0.0f));
            modelSMP = glm::translate(modelSMP, glm::vec3(0.0f - levoadesno, 0.0f, 0.0f - pomeraj));
            tablaShader.setMat4("uM", modelSMP);

            glBindVertexArray(VAO[3]);
            glDrawArrays(GL_TRIANGLES, 0, 6);

            ////////////////////////////////////////////////////////////////////
            //PODEOK


            podeokShader.use();
            podeokShader.setFloat("providnost", 1.0);

            podeokShader.setVec3("pointLight1.position", glm::vec3(0.0f - levoadesno, 0.5f, 0.5f - pomeraj));
            podeokShader.setVec3("pointLight1.ambient", tlamb, 0.15, tlamb);
            podeokShader.setVec3("pointLight1.diffuse", tldif, 0.5, tldif);
            podeokShader.setVec3("pointLight1.specular", tlspec, 0.7, tlspec);

            podeokShader.setVec3("uLight.kA", ulamb, 0.1, ulamb);
            podeokShader.setVec3("uLight.kD", uldif, 0.3, uldif);
            podeokShader.setVec3("uLight.kS", ulspec, 0.8, ulspec);



            podeokShader.setMat4("uV", view);

            podeokShader.setVec3("uViewPos", cameraPos);

            modelPodeok = glm::translate(modelPodeokKretanje, glm::vec3(0.0f-levoadesno, 0.0f, 0.0f - pomeraj));
            modelPodeok = glm::scale(modelPodeok, glm::vec3(pomerenoPodeoka,1.0f,1.0f));
            podeokShader.setMat4("uM", modelPodeok);
            glBindVertexArray(VAO[1]);
            glDrawArrays(GL_TRIANGLES, 0, 6);

            //////////////////////////////////////////////////////////////////////
            //SIJALICA CRVENA
            sijalicaShader.use();
            sijalicaShader.setBool("nv", nv);
            sijalicaShader.setFloat("crvena", crvena);
            glm::mat4 modelSijalica = glm::mat4(1.0f);
            modelSijalica= glm::translate(modelSijalica, glm::vec3(0.0f - levoadesno, 0.0f, 0.0f - pomeraj));
            sijalicaShader.setMat4("uM", modelSijalica);
            sijalicaShader.setMat4("uV", view);
            glBindVertexArray(VAO[9]);
            glDrawArrays(GL_TRIANGLES, 0, 6);

            //////////////////////////////////////////////////////////////////////
            //SIJALICA PLAVA
            sijalica2Shader.use();
            sijalica2Shader.setBool("nv", nv);
            sijalica2Shader.setFloat("plava", plava);
            glm::mat4 model2Sijalica = glm::mat4(1.0f);
            model2Sijalica = glm::translate(model2Sijalica, glm::vec3(0.0f - levoadesno-0.5, 0.0f, 0.0f - pomeraj));
            sijalica2Shader.setMat4("uM", model2Sijalica);
            sijalica2Shader.setMat4("uV", view);
            glBindVertexArray(VAO[9]);
            glDrawArrays(GL_TRIANGLES, 0, 6);


            ///////////////////////////////////////////////////////////////////
            //SIJALICA ZUTA
            sijalica3Shader.use();
            sijalica3Shader.setFloat("zuta",abs(sin(glfwGetTime()))*float(stepen));
            glm::mat4 model3Sijalica = glm::mat4(1.0f);
            model3Sijalica = glm::translate(model3Sijalica, glm::vec3(0.0f - levoadesno - 1.0, 0.0f, 0.0f - pomeraj));
            sijalica3Shader.setMat4("uM", model3Sijalica);
            sijalica3Shader.setMat4("uV", view);
            glBindVertexArray(VAO[9]);
            glDrawArrays(GL_TRIANGLES, 0, 6);



        }

         

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}




unsigned int loadTexture(char const* path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}