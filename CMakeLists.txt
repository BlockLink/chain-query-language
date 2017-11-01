cmake_minimum_required(VERSION 3.8)
project(chain_query_language)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        chain-query-language/chainsql/chainsql_lang_parser.cpp
        chain-query-language/chainsql/chainsql_meta_executor.cpp
        chain-query-language/chainsql/chainsql_rollback_translator.cpp
        chain-query-language/chainsql/chainsql_structure_listener.cpp
        chain-query-language/chainsql/chainsql_to_sql_translator.cpp
        chain-query-language/chainsql/chainsql_types.cpp
        chain-query-language/chainsql/chainsqlBaseListener.cpp
        chain-query-language/chainsql/chainsqlContext.cpp
        chain-query-language/chainsql/chainsqlLexer.cpp
        chain-query-language/chainsql/chainsqlListener.cpp
        chain-query-language/chainsql/chainsqlParser.cpp
        chain-query-language/chainsql/utils.cpp
        chain-query-language-runner/main.cpp)

include_directories(chain-query-language/include ./lib/antlr4-runtime/antlr4 ../fc/include /usr/local/lib/boost/include)

link_directories(../fc /usr/local/lib/boost/lib ../link-antlr-cpp/dist)

link_libraries(fc boost_system boost_system boost_chrono boost_date_time boost_coroutine boost_context boost_thread boost_filesystem pthread
        antlr4-runtime)

add_executable(chain_query_language ${SOURCE_FILES})