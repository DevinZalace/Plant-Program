#ifndef TERMINAL_UI_H
#define TERMINAL_UI_H

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Lightweight console UI helpers for rendering menus and plant details.
namespace TerminalUI {
	inline constexpr int contentWidth = 76;
	inline constexpr int textWidth = contentWidth - 2;

	inline constexpr const char* reset = "\033[0m";
	inline constexpr const char* bold = "\033[1m";
	inline constexpr const char* green = "\033[38;5;34m";
	inline constexpr const char* brightGreen = "\033[38;5;82m";
	inline constexpr const char* gold = "\033[38;5;220m";
	inline constexpr const char* cyan = "\033[38;5;45m";
	inline constexpr const char* muted = "\033[38;5;245m";
	inline constexpr const char* red = "\033[38;5;196m";

	// Clear the console screen and move the cursor to the top-left corner.
	inline void clearScreen() {
		std::cout << "\033[2J\033[H";
	}

	// Draw a simple border line for the current UI panel.
	inline void printBorder(char fill = '-') {
		std::cout << green << '+' << std::string(contentWidth, fill) << '+' << reset << '\n';
	}

	inline void printLine(const std::string& text = "", const char* color = reset) {
		const std::string visibleText = text.substr(0, textWidth);
		std::cout << green << '|' << reset
			<< ' ' << color << std::left << std::setw(textWidth) << visibleText << reset
			<< ' ' << green << '|' << reset << '\n';
	}

	inline void printCentered(const std::string& text, const char* color = reset) {
		const std::string visibleText = text.substr(0, textWidth);
		const int leftPadding = static_cast<int>((textWidth - visibleText.size()) / 2);
		const int rightPadding = textWidth - static_cast<int>(visibleText.size()) - leftPadding;

		std::cout << green << '|' << reset << ' '
			<< std::string(leftPadding, ' ') << color << visibleText << reset
			<< std::string(rightPadding, ' ') << ' '
			<< green << '|' << reset << '\n';
	}

	// Render a title block with an optional subtitle beneath it.
	inline void printTitle(const std::string& title, const std::string& subtitle = "") {
		printBorder('=');
		printCentered(title, brightGreen);
		if (!subtitle.empty()) {
			printCentered(subtitle, muted);
		}
		printBorder('=');
	}

	// Render a single menu option in the main navigation list.
	inline void printMenuOption(const std::string& key, const std::string& label) {
		std::ostringstream line;
		line << "  [" << key << "]  " << label;
		printLine(line.str(), cyan);
	}

	// Wrap long text so it fits neatly within the console width.
	inline std::vector<std::string> wrapText(const std::string& text, std::size_t width) {
		std::vector<std::string> lines;
		std::istringstream words(text);
		std::string word;
		std::string line;

		while (words >> word) {
			if (line.empty()) {
				line = word;
			}
			else if (line.size() + word.size() + 1 <= width) {
				line += ' ' + word;
			}
			else {
				lines.push_back(line);
				line = word;
			}
		}

		if (!line.empty()) {
			lines.push_back(line);
		}
		if (lines.empty()) {
			lines.push_back("");
		}

		return lines;
	}

	// Render a labeled field with wrapped content for long values.
	inline void printField(const std::string& label, const std::string& value) {
		constexpr int labelWidth = 12;
		constexpr int separatorWidth = 2;
		constexpr int valueWidth = textWidth - labelWidth - separatorWidth;
		const std::vector<std::string> valueLines = wrapText(value, valueWidth);

		for (std::size_t i = 0; i < valueLines.size(); ++i) {
			const std::string currentLabel = (i == 0) ? label : "";
			const int padding = valueWidth - static_cast<int>(valueLines[i].size());

			std::cout << green << '|' << reset << ' '
				<< gold << std::left << std::setw(labelWidth) << currentLabel << reset
				<< std::string(separatorWidth, ' ')
				<< valueLines[i] << std::string(padding, ' ') << ' '
				<< green << '|' << reset << '\n';
		}
	}

	// Read a single line of user input with a prompt.
	inline std::string readLine(const std::string& prompt) {
		std::cout << gold << prompt << reset;
		std::string input;
		std::getline(std::cin, input);
		return input;
	}

	// Remove leading and trailing whitespace from a string.
	inline std::string trim(std::string text) {
		const auto first = std::find_if_not(text.begin(), text.end(), [](unsigned char character) {
			return std::isspace(character);
		});
		const auto last = std::find_if_not(text.rbegin(), text.rend(), [](unsigned char character) {
			return std::isspace(character);
		}).base();

		if (first >= last) {
			return "";
		}
		return std::string(first, last);
	}

	// Convert text to lowercase for case-insensitive comparisons.
	inline std::string lowercase(std::string text) {
		std::transform(text.begin(), text.end(), text.begin(), [](unsigned char character) {
			return static_cast<char>(std::tolower(character));
		});
		return text;
	}

	// Pause execution until the user presses Enter.
	inline void pause() {
		std::cout << '\n' << muted << "Press Enter to return to the menu..." << reset;
		std::string ignored;
		std::getline(std::cin, ignored);
	}
}

#endif
