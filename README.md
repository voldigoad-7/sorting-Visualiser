# Sorting Visualizer

This project visualizes various sorting algorithms using the SDL2 library. The visualization shows how different sorting algorithms work by graphically representing the sorting process.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Available Sorting Algorithms](#available-sorting-algorithms)
- [Contributing](#contributing)
- [License](#license)

## Installation

### Prerequisites

- **Homebrew**: Package manager for macOS. Install from [Homebrew's website](https://brew.sh/).
- **SDL2**: Simple DirectMedia Layer library.

### Steps

1. **Install SDL2 using Homebrew**:
    ```sh
    brew install sdl2
    ```

2. **Clone the repository**:
    ```sh
    git clone https://github.com/your-username/sorting-visualizer.git
    cd sorting-visualizer
    ```

3. **Open the project in Visual Studio Code**:
    ```sh
    code .
    ```

4. **Set up include paths in Visual Studio Code**:

    - Open the command palette (`Cmd+Shift+P`) and select `C/C++: Edit Configurations (UI)`.
    - Add the following include paths to your `c_cpp_properties.json` file:

        ```json
        {
            "configurations": [
                {
                    "name": "Mac",
                    "includePath": [
                        "${workspaceFolder}/**",
                        "/usr/local/include",
                        "/usr/local/include/SDL2", // or "/opt/homebrew/include/SDL2" for Apple Silicon
                        "/Library/Developer/CommandLineTools/usr/include/c++/v1",
                        "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include"
                    ],
                    "defines": [],
                    "macFrameworkPath": [
                        "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"
                    ],
                    "compilerPath": "/usr/bin/clang",
                    "cStandard": "c11",
                    "cppStandard": "c++17",
                    "intelliSenseMode": "macos-clang-x64"
                }
            ],
            "version": 4
        }
        ```

5. **Compile and Run**:
    ```sh
    g++ main.cpp -o sorting_visualization -lSDL2
    ./sorting_visualization
    ```

## Usage

To run the sorting visualizer, use the provided `main.cpp` file. The program initializes an SDL2 window and displays a graphical representation of a sorting algorithm in action.

### Selecting a Sorting Algorithm

You can select which sorting algorithm to visualize by uncommenting the corresponding function call in the `main` function of `main.cpp`. For example:

```cpp
int main(int argc, char* args[]) {
    // ... [initialization code]

    // Uncomment the sorting algorithm you want to visualize:
    // bubbleSort(renderer);
    // selectionSort(renderer);
    // insertionSort(renderer);
    // mergeSort(renderer);
    // quickSort(renderer);

    // ... [cleanup code]
}

Available Sorting Algorithms
Bubble Sort: bubbleSort(renderer)
Selection Sort: selectionSort(renderer)
Insertion Sort: insertionSort(renderer)
Merge Sort: mergeSort(renderer, 0, NUM_BARS - 1)
Quick Sort: quickSort(renderer, 0, NUM_BARS - 1)


Contributing
Contributions are welcome! Please follow these steps to contribute:

Fork the repository.
Create a new branch: git checkout -b my-feature-branch
Make your changes and commit them: git commit -m 'Add some feature'
Push to the branch: git push origin my-feature-branch
Submit a pull request.

License
This project is licensed under the MIT License. See the LICENSE file for details.
