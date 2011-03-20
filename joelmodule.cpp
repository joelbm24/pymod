#include <Python.h>
#include <iostream>

static PyObject * is_cool(PyObject *self, PyObject *args)
{

    std::cout << "Joel is cool\n";
    return Py_None;
}

static PyMethodDef JoelMethods[] = {
    {"is_cool",  is_cool, METH_VARARGS,
        "Cool method"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC initjoel(void)
{
    (void) Py_InitModule("joel", JoelMethods);
}

int main(int argc, char *argv[])
{
    /* Pass argv[0] to the Python interpreter */
    Py_SetProgramName(argv[0]);

    /* Initialize the Python interpreter.  Required. */
    Py_Initialize();

    /* Add a static module */
    initjoel();
}
