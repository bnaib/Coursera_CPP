#include "node.h"

EmptyNode::EmptyNode() {}

bool EmptyNode::Evaluate(
  const Date& date,
  const string& event) const { return true; }

DateComparisonNode::DateComparisonNode(
  const Comparison& c, const Date& date)
  : C(c), D(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const std::string& event) const
{
  switch (this->C) {
    case Comparison::Less:
      return date < this->D;	
    case Comparison::LessOrEqual:
      return date <= this->D;	
    case Comparison::Greater:
      return date > this->D;	
    case Comparison::GreaterOrEqual:
      return date >= this->D;	
    case Comparison::Equal:
      return date == this->D;	
    case Comparison::NotEqual:
      return date != this->D;
  }
  return false;
}

EventComparisonNode::EventComparisonNode(
  const Comparison& c, const string& event) : C(c), Event(event) {}

bool EventComparisonNode::Evaluate(const Date& date, const std::string& event) const
{
  switch (this->C) {
    case Comparison::Less:
      return event < this->Event;
    case Comparison::LessOrEqual:
      return event <= this->Event;
    case Comparison::Greater:
      return event > this->Event;
    case Comparison::GreaterOrEqual:
      return event >= this->Event;
    case Comparison::Equal:
      return event == this->Event;
    case Comparison::NotEqual:
      return event != this->Event;
  }
  return false;
}

LogicalOperationNode::LogicalOperationNode(
  const LogicalOperation& lo, 
  const std::shared_ptr<Node>& l_node,
  const std::shared_ptr<Node>& r_node) : LO(lo), LNode(l_node), RNode(r_node) {}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event) const
{
  switch (this->LO) {
    case LogicalOperation::Or:
      return LNode->Evaluate(date, event) || RNode->Evaluate(date, event);
    case LogicalOperation::And:
      return LNode->Evaluate(date, event) && RNode->Evaluate(date, event);
  }
  return (false);
}
