#pragma once

#include "date.h"

#include <memory>

using namespace std;

enum class Comparison {
  Less,
  LessOrEqual,
  Greater,
  GreaterOrEqual,
  Equal,
  NotEqual
};

enum class LogicalOperation {
  Or,
  And
};

class Node {
  public:
    virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

class EmptyNode : public Node {
public:
	EmptyNode();
	bool Evaluate(const Date& date, const std::string& event) const override;
};

class DateComparisonNode : public Node {
  private:
    const Comparison C;
    const Date D;
  public:
    DateComparisonNode(const Comparison& c, const Date& date);
    bool Evaluate(const Date& date, const std::string& event) const override;
};

class EventComparisonNode : public Node {
  private:
    const Comparison C;
    const string Event;
  public:
    EventComparisonNode(const Comparison& c, const std::string& event);
    bool Evaluate(const Date& date, const std::string& event) const override;
};

class LogicalOperationNode : public Node {
  private:
    const LogicalOperation LO;
    const shared_ptr<Node> LNode;
    const shared_ptr<Node> RNode;
  public:
    LogicalOperationNode(const LogicalOperation& lo, 
              const std::shared_ptr<Node>& l_node,
              const std::shared_ptr<Node>& r_node);
    bool Evaluate(const Date& date, const std::string& event) const override;
};
