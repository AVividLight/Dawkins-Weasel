# Dawkin's Weasel
Evolutionary String Matching

This is my attempt at one of 2Cat Studios' programmer challenges, an implementation of Dawkin's Weasel. The challenge was great fun, and prompted me to learn about several new topics, one of which manifested itself as the included localisation code (I got massively sidetracked). I did my best to keep my wanderings and the challenge separate, so if you're only interested in evolutionary string matching, just look at [EvolutionManager.cpp](https://github.com/AVividLight/Dawkins-Weasel/blob/master/src/EvolutionManager.cpp), and know that `InputOutput::SendOutput (string, bool)` is my wrapper for `std::cout`.

Overall, I'm quite proud of how this turned out, but I don't have much to compare it to. The code is probably pretty inefficient compared to some of the other evolutionary algorithms out there, although I actually haven't seen the source for any others myself. More fine-tuning could certainly be done, too. Specifically, the `const int MUTATION_CHANCE` is 0.05, which is a value I blindly picked from Wikipedia. I'm sure it could be more accurate.

You're free to use this code however you like, I hereby relinquish my rights of ownership, and release the project into the public domain. Attribution or links to https://2catstudios.github.io are appreciated!

### For more info, please visit [https://2CatStudios.github.io/challenges](https://2catstudios.github.io/challenges.html#dawkins_weasel)

This software is based on pugixml library (http://pugixml.org).
pugixml is Copyright (C) 2006-2015 Arseny Kapoulkine.
