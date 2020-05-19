### [OpenGL Object](https://www.khronos.org/opengl/wiki/OpenGL_Object)

#### [glGenBuffers](https://www.khronos.org/registry/OpenGL-Refpages/es2.0/xhtml/glGenBuffers.xml)
Basicamente retorna um buffer object.
Nenhum buffer object é associado com o buffer object retornado pela função até que o valor retornado seja vinculado pela primeira vez chamando [glBindBuffer](https://www.khronos.org/registry/OpenGL-Refpages/es2.0/xhtml/glBindBuffer.xml).

#### [glBindBuffer](https://www.khronos.org/registry/OpenGL-Refpages/es2.0/xhtml/glBindBuffer.xml)

```cpp
void glBindBuffer(enum target, uint bufferName)
```

Essa função vincula um buffer object a um contexto. O target define como você pretende usar este vínculo ao buffer object.

Buffer objects carregam um array de memória linear de tamanho arbitrário. Esta memória deve ser alocada antes dela ser atualizada ou usada.

#### [glBufferData ](https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBufferData.xhtml)
  
```cpp
void glBufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage);
```

Essa função cria um novo data store para o buffer object previamente vinculado. Quando criando um novo armazenamento, qualquer armazenamento de dado pré-existente é deletado.




