cmake_minimum_required(VERSION 3.20)
project(course C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled4 main.c)

add_library(str string/string_.h string/string_.c
        string/tasks/removeNonLetters.h
        string/tasks/removeAdjacentEqualLetters.h
        string/tasks/removeExtraSpaces.h
        string/tasks/digitToStart.h
        string/tasks/digitToStartSymbolEnd.h
        string/tasks/digitToEndReversSymbolToStartString.h
        string/tasks/digitToStartNonReversString.h
        string/tasks/reverseWordInString.h
        string/tasks/digitSpace.h
        string/tasks/replace.h
        string/tasks/isOrderWord.h
        string/tasks/ReverseWords.h
        string/tasks/countPallendrom.h
        string/tasks/getStringMerging.h
        string/tasks/isWordLettersSubsetStr.h
        string/tasks/deleteEqualLastWord.h
        string/tasks/deleteWordPallendrom.h
        string/tasks/deleteSequenceInWord.h
        string/tasks/deleteRepeatingCharinWord.h
        string/tasks/reverseWordOrder.h
        string/tasks/addToTheStringWithLessWord.h
        string/tasks/getWordBeforeFirstWordWithA.h
        string/tasks/areTheSameWordsInString.h
        string/tasks/wordsOfEqualLetters.h
        string/tasks/getLastWordFromFirstToSecond.h
        string/tasks/getWordBeforeFirstMatch.h
        )

add_subdirectory(libs)
target_link_libraries(untitled4 str)
target_link_libraries(untitled4 data_structures)
target_link_libraries(untitled4 algorithms)