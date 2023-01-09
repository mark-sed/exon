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

        struct Conf {
            WindowConf window_conf;  
            double fps = 60.0;
        };

    }
}

#endif//_CONFIG_HPP_