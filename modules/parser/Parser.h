

#ifndef TKOM_21Z_DANIEL_PARSER_H
#define TKOM_21Z_DANIEL_PARSER_H

#include "../token/Token.h"
#include "../errorHandler/ErrorHandler.h"
#include "Program.h"
#include "../lexer/Lexer.h"
#include <memory>
class Parser {
private:
    Token currentToken;
    Lexer lex;
public:
    Parser(Lexer lexer);
    std::unique_ptr<Program>TryToParseProgram();
//private:
    void getNextToken();
    void expect(TokenType ttype, std::string message);
    void expect_and_accept(TokenType ttype, std::string message);
    std::unique_ptr<Declaration>TryToParseVariableDeclaration();
    std::unique_ptr<INode>TryToParseFunction(int indentation);
    std::unique_ptr<IExpression>TryToParseExpression();
    std::unique_ptr<IExpression> TryToParseParenthesisExpresion();
    std::unique_ptr<IExpression> TryToParseAdvancedExpression();
    std::unique_ptr<IExpression> TryToParseBasicExpression();
    std::unique_ptr<FunCall> TryToParseFunctionCall(std::string id);
    std::unique_ptr<Return> TryToParseReturnStatement();
    std::unique_ptr<While>TryToParseWhileStatement(int indentation);
    std::unique_ptr<If> TryToParseIfStatement(int indentation);
    std::unique_ptr<Else> TryToParseElseStatement(int indentation);
    std::unique_ptr<IExpression> TryToParseCondition();
    std::unique_ptr<IExpression> TryToParseRelationalCondition();
    std::unique_ptr<IExpression> TryToParseBasicCondition();
    std::unique_ptr<IExpression> TryToParseParenthesisCondition();
    std::unique_ptr<Body> TryToParseBody(int indentation);
    std::vector<std::shared_ptr<IExpression>> TryToParseArguments();
    std::vector<VariableDeclr> TryToParseParameters();
    std::unique_ptr<INode> TryToParseFunctionOrVarDefinition(int indentation);
    std::unique_ptr<INode> TryToParseAssignOrFunCall();
    std::unique_ptr<AssignStatement> TryToParseAssignStatement(std::string id);
    TypeOfData getTypeOfData(TokenType type);
    std::string getOperatorType();
    std::unique_ptr<Expression>CreateExpression(std::string basicString, std::unique_ptr<IExpression> expression, std::unique_ptr<IExpression> expression1);
    std::unique_ptr<Condition> CreateCondition(std::string basicString, std::unique_ptr<IExpression> expression, std::unique_ptr<IExpression> expression1);
    std::unique_ptr<RelationalCondition> CreateRelationalCondition(std::string basicString, std::unique_ptr<IExpression> expression, std::unique_ptr<IExpression> expression1);
    std::unique_ptr<AdvExpression>CreateAdvExpression(std::string basicString, std::unique_ptr<IExpression> expression, std::unique_ptr<IExpression> expression1);
};


#endif //TKOM_21Z_DANIEL_PARSER_H
