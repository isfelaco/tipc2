#pragma once

#include "ASTNode.h"
#include "ASTDeclNode.h"
#include "ASTStmt.h"
#include "ASTDeclStmt.h"
#include "ASTExpr.h"

/*! \brief Class for defining the signature, local declarations, and a body of a function.
 */
class ASTFunction : public ASTNode {
  std::shared_ptr<ASTDeclNode> DECL;
  std::vector<std::shared_ptr<ASTDeclNode>> FORMALS;
  std::vector<std::shared_ptr<ASTDeclStmt>> DECLS;
  std::vector<std::shared_ptr<ASTStmt>> BODY;
  std::vector<std::shared_ptr<ASTExpr>> RETURNS;
public:
  std::vector<std::shared_ptr<ASTNode>> getChildren() override;
  ASTFunction(std::shared_ptr<ASTDeclNode> DECL, 
           std::vector<std::shared_ptr<ASTDeclNode>> FORMALS,
           std::vector<std::shared_ptr<ASTDeclStmt>> DECLS,
           std::vector<std::shared_ptr<ASTStmt>> BODY,
           std::vector<std::shared_ptr<ASTExpr>> RETURNS);
  ~ASTFunction()=default;
  ASTDeclNode* getDecl() const { return DECL.get(); };
  std::string getName() const { return DECL->getName(); };
  std::vector<ASTDeclNode*> getFormals() const;
  std::vector<ASTDeclStmt*> getDeclarations() const;
  std::vector<ASTStmt*> getStmts() const;
  std::vector<ASTExpr*> getReturnExprs();
  void accept(ASTVisitor * visitor) override;
  llvm::Value* codegen() override;

protected:
  std::ostream& print(std::ostream &out) const override;
};
