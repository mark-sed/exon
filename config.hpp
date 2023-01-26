#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_

#include <string>

namespace exon {

    namespace conf {

        struct WindowConf {
            std::string title;
            unsigned int width;
            unsigned int height;
        };

        struct SpriteConf {
            std::string basepath;
            float scale = 1.0;
            bool load_from_sting;
        };

        struct Conf {
            WindowConf window_conf;
            SpriteConf sprite_conf;
            double fps = 60.0;
        };


    }
}

#endif//_CONFIG_HPP_