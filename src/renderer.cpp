#include "include/renderer.hpp"

// set the defaults of the board config
Renderer::Renderer() : xMargin(0), yMargin(0), 
                       spaceWidth(0), spaceHeight(0), 
                       cellWidth(0.6f), cellHeight(1.2f),
                       lightColor("white"), darkColor("blue") {

    std::string rowString = runCommand("tput lines");
    std::string colString = runCommand("tput cols");

    // convert to ints and store for later use
    rows = std::stoi(rowString);
    cols = std::stoi(colString);

    // check for config file
    std::string result = runCommand("ls -la | grep chess.cfg");
    if (!result.empty()) {
        // parse the input config file
        parseConfigFile("chess.cfg");
    }
}

Renderer::~Renderer()
{}

void Renderer::parseConfigFile(std::string filepath) {
    // open the file and read the contents
    // gonna use a simple key,value format for the desired settings
    std::ifstream file(filepath);
    if (!file.is_open()) 
        throw std::runtime_error("failed to open config file");

    std::string line;
    std::vector<std::string> strings;
    while (std::getline(file, line, ',')) {
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        strings.push_back(line);
    }

    // we now have a vector where each key and value is split apart
    // need to safely iterate through
    int endIdx = strings.size() - 1;
    for (size_t i = 0; i < strings.size(); i++) {
        std::string s = strings[i];

        if (i < endIdx) {
            if (s == "xMargin")
                xMargin = std::stoi(strings[i + 1]);
            else if (s == "yMargin")
                yMargin = std::stoi(strings[i + 1]);
            else if (s == "spaceWidth")
                spaceWidth = std::stoi(strings[i + 1]);
            else if (s == "spaceHeight")
                spaceHeight = std::stoi(strings[i + 1]);
            else if (s == "cellWidth")
                cellWidth = std::stof(strings[i + 1]);
            else if (s == "cellHeight")
                cellHeight = std::stof(strings[i + 1]);
            else if (s == "lightColor")
                lightColor = strings[i + 1];
            else if (s == "darkColor")
                darkColor = strings[i + 1];
        }
    }

    file.close();
}

std::string Renderer::runCommand(const char *cmd) const {
    std::array<char, 128> buffer;
    std::string result;

    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe)
        throw std::runtime_error("popen() failed");

    while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr)
        result += buffer.data();

    return result;
}

// returns reset as default
std::string Renderer::colorToANSI(std::string color) const {
    if (color == "black")
        return "\033[40m";
    else if (color == "red")
        return "\033[41m";
    else if (color == "green")
        return "\033[42m";
    else if (color == "yellow")
        return "\033[43m";
    else if (color == "blue")
        return "\033[44m";
    else if (color == "magenta")
        return "\033[45m";
    else if (color == "cyan")
        return "\033[46m";
    else if (color == "white")
        return "\033[47m";
    else if (color == "default")
        return "\033[41m";
    
    return "\033[0m"; // resets all colors AND effects
}

void Renderer::render() {
    int ratio = static_cast<int>(cellHeight / cellWidth);
    if (ratio == 0) 
        ratio = 1;

    std::string outputPrint(ratio, ' ');

    // reset terminal and get going
    std::cout << "\033[2J\033[1;1H";
    
    std::string light = colorToANSI(lightColor);
    std::string dark = colorToANSI(darkColor);
    std::string reset = colorToANSI("");

    // adjust for x and y margins
    int yMax = (spaceHeight * 8) + yMargin;
    int xMax = (spaceWidth * 8) + xMargin;
    for (int y = 0; y < yMax; y++) { // rows
        for (int x = 0; x < xMax; x++) { // colums
            if (y < yMargin || x < xMargin) {
                std::cout << " ";
                continue;
            }

            int normalizedX = x - xMargin;
            int normalizedY = y - yMargin;

            if ((normalizedX % (spaceWidth * 2)) < spaceWidth) {
                // these rows alternate light to dark
                if ((normalizedY % (spaceHeight * 2)) < spaceHeight)
                    std::cout << light << outputPrint << reset;
                else
                    std::cout << dark << outputPrint << reset;
            }
            else {
                // these rows alternate dark to light
                if ((normalizedY % (spaceHeight * 2)) < spaceHeight)
                    std::cout << dark << outputPrint << reset;
                else
                    std::cout << light << outputPrint << reset;
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < yMargin; i++)
        std::cout << std::endl;
}
