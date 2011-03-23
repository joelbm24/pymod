#include <Python.h>
#include <iostream>
#include <string>
using namespace std;

static PyObject * is_cool(PyObject *self, PyObject *args)
{
    return Py_BuildValue("s", "Joel is cool");
}

static PyObject * add(PyObject *self, PyObject *args)
{
    int num1,num2;
    if (!PyArg_ParseTuple(args, "ii", &num1,&num2))
                return NULL;
    return Py_BuildValue("i", num1+num2);
}

static PyObject * system(PyObject *self, PyObject *args)
{
        const char *cmd;

        if (!PyArg_ParseTuple(args, "s", &cmd))
            return NULL;
        FILE* pipe = popen(cmd, "r");
        if (!pipe) {
            PyErr_SetString(JoelError, "System command failed");
            return NULL;
        }
        char buffer[128];
        string result = "";
        while(!feof(pipe))
        {
            if(fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
        pclose(pipe);

        return Py_BuildValue("s", result.c_str());
}

static PyMethodDef JoelMethods[] = {
    {"is_cool",  is_cool, METH_VARARGS,
        "Cool method"},
    {"add", add, METH_VARARGS, "Add two numbers"},
    {"system", system, METH_VARARGS, "Run a system command and return the result"},
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
