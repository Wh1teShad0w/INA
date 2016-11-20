import inspect
import json
import os

def find_config():
    # Pour une compatibilité ascendante, recherchez 'config' ou 'config.json'
    if os.path.exists('config'):
        return 'config'
    return 'config.json'

def save(conf):
    json.dump(conf, open(find_config(), 'w'), sort_keys=True, indent=2)

if not os.path.exists(find_config()):
    open('config.json', 'w').write(inspect.cleandoc(
        r'''
        {
          "connections":
          {
            "local irc":
            {
              "server": "localhost",
              "nick": "skybot",
              "channels": ["#test"]
            }
          },
          "prefix": ".",
          "disabled_plugins": [],
          "disabled_commands": [],
          "acls": {},
          "api_keys": {},
          "censored_strings":
          [
            "DCC SEND",
            "1nj3ct",
            "thewrestlinggame",
            "startkeylogger",
            "hybux",
            "\\0",
            "\\x01",
            "!coz",
            "!tell /x"
          ]
        }''') + '\n')


def config():
    # Recharger config du fichier si le fichier a changé
    config_mtime = os.stat(find_config()).st_mtime
    if bot._config_mtime != config_mtime:
        try:
            bot.config = json.load(open(find_config()))
            bot._config_mtime = config_mtime
            for name, conf in bot.config['connections'].iteritems():
                if name in bot.conns:
                    bot.conns[name].set_conf(conf)
                else:
                    if conf.get('ssl'):
                        bot.conns[name] = SSLIRC(conf)
                    else:
                        bot.conns[name] = IRC(conf)
        except ValueError, e:
            print 'ERROR: dans la configuration!', e


bot._config_mtime = 0
