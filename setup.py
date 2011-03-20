from distutils.core import setup, Extension

module1 = Extension('joel',
                    sources = ['joelmodule.cpp'])
setup (name = 'Joel is cool',
       author = 'Joel Moore',
       author_email = 'joelbm24@gmail.com',
       version = '1.0',
       description = 'This is a cool package',
       ext_modules = [module1])
