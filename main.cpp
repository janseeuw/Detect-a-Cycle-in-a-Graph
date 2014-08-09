enum Color { WHITE, GRAY, BLACK };

template<EdgeType RT>
class CyclicGraph: public virtual Graph<RT>{
public:
	CyclicGraph(int n=0):Graph<RT>(n){};
	bool isCyclic(){
		std::vector<Color> color(this->numberOfVertices(), WHITE);
		bool loop = false;
		for(int i=0; i<this->numberOfVertices(); i++){
			if(color[i] == WHITE){
				visit(i, color, loop);
			}
		}
		return loop;
	}
private:
	void visit(int v, std::vector<Color> &color, bool &loop){
		color[v] = GRAY;
		std::map<int,int>::iterator it = this->vertices[v].begin();
		while(it != this->vertices[v].end()){
			if(color[it->first] == WHITE){
				visit(it->first, color, loop);
			}else{
				if(color[it->first] == GRAY) loop = true; // G -> G: back edge
			}
			it++;
		}
		color[v] = BLACK;
	}
};

int main(int argc, char *argv[]){
	const int N=4;
	
	CyclicGraph<DIRECTED>g(N);
	
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	
	if(!g.isCyclic()){
		std::cout<<"Graph contains no cycles";
	}else{
		std::cout<<"Graph contains a cycle";
	}
	
    return 0;
}