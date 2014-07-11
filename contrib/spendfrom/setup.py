from distutils.core import setup
setup(name='btcspendfrom',
      version='1.0',
      description='Command-line utility for yescoin "coin control"',
      author='Gavin Andresen',
      author_email='gavin@yescoinfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
