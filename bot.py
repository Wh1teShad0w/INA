#!/usr/bin/env python
# Debut de INA
import os
import Queue
import sys
import traceback
import time


class Bot(object):
    def __init__(self):
        self.conns = {}
        self.persist_dir = os.path.abspath('persist')
        if not os.path.exists(self.persist_dir):
            os.mkdir(self.persist_dir)

ina = Bot()

def main():
    sys.path += ['plugins']  # so 'import hook' works without duplication
    sys.path += ['lib']
    os.chdir(os.path.dirname(__file__) or '.')  # do stuff relative to the install directory

    print 'Chargement des plugins...'

    # bootstrap the reloader
    eval(compile(open(os.path.join('core', 'reload.py'), 'U').read(),
                 os.path.join('core', 'reload.py'), 'exec'),
         globals())
    reload(init=True)

    print 'Connection a l\'IRC'

    try:
        config()
        if not hasattr(bot, 'config'):
            exit()
    except Exception, e:
        print 'ERROR: Mauvaiz confirm:', e
        traceback.print_exc()
        sys.exit()

    print 'Lancement de la function de base principalle'

    while True:
        reload() 
        config()
        
        for conn in bot.conns.itervalues():
            try:
                out = conn.out.get_nowait()
                main(conn, out)
            except Queue.Empty:
                pass
        while all(conn.out.empty() for conn in bot.conns.itervalues()):
            time.sleep(.1)

if __name__ == '__main__':
    main()
